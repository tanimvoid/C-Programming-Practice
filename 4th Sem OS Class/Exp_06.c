// 6. To write C programs to simulate UNIX command pipe()
// Platform: Linux

#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define msgsize 16

int main() {
    char *msg = "hello world";
    char inbuff[msgsize];
    int p[2], pid, j;
    pipe(p);
    pid = fork();
    if (pid > 0) {
        close(p[0]);
        write(p[1], msg, strlen(msg) + 1);
    }
    if (pid == 0) {
        close(p[1]);
        read(p[0], inbuff, msgsize);
        printf("%s \n", inbuff);
    }
}