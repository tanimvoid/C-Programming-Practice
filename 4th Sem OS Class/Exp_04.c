// 4. To write C programs to simulate UNIX command wait()
// Platform: Linux

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int i = 0, pid;
    pid = fork();
    if (pid == 0) {
        printf("child process started\n");
        for (i = 0; i < 10; i++)
            printf("\n%d", i);
        printf("\n child process ends");
    } else {
        printf("\n parent process starts");
        wait(0);
        printf("\n parent process ends");
    }
}