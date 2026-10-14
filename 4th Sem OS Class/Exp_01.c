// 1. To write C programs to simulate UNIX command fork()
// Platform: Linux

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        printf("\n I am the child");
        printf("\n I am the parent :%d", getppid());
        printf("\n I am the child :%d", getpid());
    }
    else
    {
        printf("\n I am the parent ");
        printf("\n I am the parents parent :%d", getppid());
        printf("\n I am the parent :%d\n", getpid());
    }
}