// 2. To write C programs to simulate UNIX command execv()
// Platform: Linux

#include <stdio.h>
#include <unistd.h>
int main() {
    char *temp[3];
    temp[0] = "ls";
    temp[1] = "-l";
    temp[2] = (char *)0;
    execv("/bin/ls", temp);
    printf("this will not print\n");
}