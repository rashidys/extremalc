#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    printf("This is the parent process with pricess ID: %d\n", getpid());
    printf("Before calling fork() ...\n");
    pid_t ret = fork();
    if (ret) {
        printf("The child process is spawned with PID: %d\n", ret);
    } else {
        printf("This is the child process with PID: %d\n", getpid());
    }

    printf("Type CTL+C to exit ...\n");
    while (1);
    return 0;


}
