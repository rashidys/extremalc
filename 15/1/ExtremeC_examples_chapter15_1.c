#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

void* thread_body(void* arg){
    printf("Hello from first thread!\n");
    return 0;
}


int main(int argc, char** argv){
    pthread_t thread;

    int result = pthread_create(&thread, NULL, thread_body, NULL);

    if (result) {
        printf("Thread could not be created. Error number: %d\n", result);
        exit(1);
    }
    result = pthread_join(thread, NULL);

    if (result) {
        printf("The thread could not be joined. Error number: %d\n", result);
        exit(2);
    }
    return 0;
}
