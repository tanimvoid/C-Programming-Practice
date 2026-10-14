// 3. To write C programs to simulate UNIX command execlp()
// Platform: Linux

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    int pid;
    pid = fork();
    if (pid == 0) {
        printf("\n fork program started");
        execlp("/bin/ls", "ls", NULL);
    } else {
        printf("\nend");
    }
}