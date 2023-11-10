#include <stdio.h>
#include <semaphore.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#define SHARED_MEM_SIZE 4
int shared_fd = -1;

int32_t* counter = NULL;

sem_t* semaphore = NULL;

void init_control_mechanism() {
    semaphore = sem_open("/sem0", O_CREAT | O_EXCL, 0600, 1);
    if (semaphore == SEM_FAILED) {
        fprintf(stderr, "ERROR: Opening the semaphore failed: %s\n", strerror(errno));
        exit(1);
    }
}

void shutdown_control_mechanism() {
    if (sem_close(semaphore) < 0) {
        fprintf(stderr, "ERROR: Closing the semaphore failed: %s\n", strerror(errno));
        exit(1);
    }
    if (sem_unlink("/sem0") < 0) {
        fprintf(stderr, "ERROR: Unlinking failed: %s\n", strerror(errno));
        exit(1);
    }
}
void init_shared_resource() {                                                                        
    shared_fd = shm_open("/shm0", O_CREAT | O_RDWR, 0600);                                           
    if (shared_fd < 0) {                                                                             
        fprintf(stderr, "ERROR: Failed to create shared memory: %s\n", strerror(errno));             
        exit(1);                                                                                     
    }                                                                                                
    fprintf(stdout, "Shared memory is created with fd: %d\n", shared_fd);                            
}                                                                                                    
                                                                                                     
void shutdown_shared_resource() {                                                                    
    if (shm_unlink("/shm0") < 0) {                                                                   
        fprintf(stderr, "ERROR: Unlinking shared memory failed: %s\n", strerror(errno));             
        exit(1);                                                                                     
    }                                                                                                
}                                                                                                    
 
void inv_counter() {
    usleep(1);
    sem_wait(semaphore);
    int32_t temp = *counter;
    usleep(1);
    *counter = temp;
    sem_post(semaphore);
    usleep(1);
}

int main(int argc, char** argv) {
    init_shared_resource();

    init_control_mechanism();

    if (ftruncate(shared_fd, SHARED_MEM_SIZE * sizeof(char)) < 0) {
            fprintf(stderr, "ERROR: Truncation failed: %s\n", strerror(errno));
                        return 1;
        }
    fprintf(stdout, "The memory region is truncated.\n");

    void* map = mmap(0, SHARED_MEM_SIZE, PROT_WRITE, MAP_SHARED, shared_fd, 0);

    if (map == MAP_FAILED) {
        fprintf(stderr, "ERROR: Mapping failed: %s\n", strerror(errno));
        return 1;
    }

    counter = (int32_t*)map;
    *counter = 0;
    pid_t pid = fork();

    if (pid) {
        inv_counter();
        fprintf(stdout, "The parent process sees the counter as %d.\n", *counter);

        int status = -1;

        wait(&status);
        fprintf(stdout, "The child process finished with status %d.\n", status);
    } else{
        inv_counter();
        fprintf(stdout, "The child process sees the counter as %d.\n", *counter);
    }
    if (munmap(counter, SHARED_MEM_SIZE) < 0) {
        fprintf(stderr, "ERROR: Unmapping failed: %s\n", strerror(errno));
        return 0;
    }
    if (close(shared_fd) < 0) {
        fprintf(stderr, "ERROR: UNmapping failed:%s\n", strerror(errno));
        return 1;
    }

    if (pid) {
        shutdown_shared_resource();
    }
    if (pid) {
        shutdown_shared_resource();
        shutdown_control_mechanism();
    }

    return 0;
}
