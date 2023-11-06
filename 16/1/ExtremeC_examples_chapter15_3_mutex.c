#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

pthread_mutex_t mtx;

void* thread_body_1(void* arg){
    int* shared_var_ptr = (int)arg;

    pthread_mutex_lock(&mtx);
    (*shared_var_ptr)++;
    printf("%d\n", *shared_var_ptr);
    pthread_mutex_unlock(&mtx);

    return NULL;
}

void* thread_body_2(void* arg) {
    int* shared_var_ptr = (int*)arg;

    pthread_mutex_lock(&mtx);
    *shared_var_ptr += 2;
    printf("%d\n", *shared_var_ptr);
    pthread_mutex_unlock(&mtx);

    return NULL;

}

int main(int argc, char** argv) {
    int shared_var = 0;

    pthread_t thread1;
    pthread_t thread2;

    pthread_mutex_init(&mtx, NULL);

    int result1 = pthread_create(&thread1, NULL, thread_body_1, &shared_var);
    int result2 = pthread_create(&thread2, NULL, thread_body_2, &shared_var);

    if (result1 || result2){
        printf("The threads could not be created.\n");
        exit(1);
    }
    

    result1 = pthread_join(thread1, NULL);
    result2 = pthread_join(thread2, NULL);

    if (result || result2) {
        printf("The threads coud not be joined.\n");
        exit(2);        
    } 

    pthread_mutex_destroy(&mtx);

    return 0;
}
