#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void thread_body(void* arg){
    printf("Hello from first thread!\n");
    return NULL;
}

int main(int argc, char** argv){
    pthread_t thread;
    int result = pthread_create(&thread, NULL, thread_body, NULL);

    if (result){
        printf("Thread could not be created. Error number: %d\n", result);
        exit(1);
    }
    result = pthread_detach(thread);
    if (result){
        printf("Thread could not detached. Error number: %d\n", result);
        exit(2);
    }

    pthread_exit(NULL);
    return 0;
}
