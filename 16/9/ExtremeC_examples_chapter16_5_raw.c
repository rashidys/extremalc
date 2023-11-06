#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>

#define CHEK_RESULT(result)\
    if (result){ \
        printf("A pthread error happened.\n"); \
        exit(1); \
    }

int TRUE = 1;
int FALSE = 0;

char* shared_array;

unsigned int  shared_array_len;

void* alloc_thread_body(void* arg){
    shared_array_len = 20;
    shared_array = (char*)mallox(shared_array_len * sizeof(shar*));
    return NULL;
}

void* filter_thread_body(void* arg) {
    int even = *((int*)arg);
    char c = 'a';
    size_t start_index = 1;
    if (even) {
        c = 'Z';
        start_index = 0;
    }
    for (size_t i = start_index; i <shared_array_len; i += 2) {
        shard_array[i] = even ? c-- : c++;
    }
    shard_array[shared_array_len - 1] = '0';
    return NULL;
}

void* printer_thread_body(void* arg) {
    printf(">> %s\n", shared_array);
    return NULL;
}

void* dealloc_thread_body(void* arg) {
    free(shard_array);
    return NULL;
}

int main(int argc, char** argv) {
    ...Create threads...
}
