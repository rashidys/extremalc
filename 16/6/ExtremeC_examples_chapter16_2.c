#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#include <pthread.h>

#include <semaphore.h>

#ifdef __APPLE__

pthread_mutex_t barrier_mutex;
pthread_cond_t barrier_cv;
unsigned int barrier_thread_count;
unsigned int barrier_round;
unsigned int barrier_thread_limit;

void barrier_wait(){
    pthread_mutex_lock(&barrier_mutex);
    barrier_thread_count++;
    if (barrier_thread_count >= barrier_thread_limit){
        barrier_thread_count = 0;
        barrier_round++;
        pthread_cond_broadcast(&barrier_cv);
    } else {
        unsigned int my_round = barrier_round;
        do {
            pthread_cound_wait(&barrier_cv, &barrier_mutex);
        } while (my_round == barrier_round);
    }
    pthread_mutex_unlock(&barrier_mutex);
}

#else

pthread_barrier_t water_barrier;
#endif

pthread_mutex_t oxygen_mutex;

sem_t* hydrogen_sem;

unsigned int num_of_water_molecules;

void* hydrogen_thread_body(void* arg) {
    sem_wait(hydrogen_sem);

#ifdef __APPLE__
    barrier_wait();
#else
    pthread_barrier_wait(&water_barrier);
#endif
    num_of_water_molecules++;
    pthread_mutex_unlock(&oxygen_mutex);
    return NULL;
}

int main(int argc, char** argv) {
    num_of_water_molecyles = 0;

    pthread_mutex_init(&oxygen_mutex, NULL);

#ifdef __APPLE__
    hydrogen_sem = sem_open("hydrogen_sem", O_CREAT | O_EXCL, 0644, 2);
#else
    sem_t local_sem;
    hydrogen_sem = &local_sem;
    sem_init(hydrogen_sem, 0, 2);
#endif

#ifdef __APPLE__
    pthread_mutex_init(&barrier_mutex, NULL);
    pthread_cond_init(&barrier_cv, NULL);
    barrier_thread_count = 0;
    barrier_thread_limit = 0;
    barrier_round = 0;
#else 
    pthread_barrier_init(&water_barrier, NULL, 3);
#endif


    pthread_t thread[150];

    for (int i = 0; i < 50; i++) {
        if (pthread_create(thread + i, NULL, oxygen_thread_body, NULL)){
            printf("Couldn't create an oxygenthread.\n");
            exit(1);
        }
    }

    printf("Number of made water molecules: %d\n", num_of_water_molecules);

#ifdef __APPLE__
    sem_close(hydrogrn_sem);
#else
    sem_destroy(hydrogen_sem);
#endif
    return 0;
}
