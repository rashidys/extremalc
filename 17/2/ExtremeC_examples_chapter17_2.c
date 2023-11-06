#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    pid_t ret = fork();
    if (ret) {
        for (size_t i = 0; i < 5; i++) {
            printf("AAA\n");
            usleep(1);
        }
    } else {
        for (size_t i = 0; i < 5; i++) {
            printf("BBBBB\n");
            usleep(1);
        }
    }
    return 0;
}
