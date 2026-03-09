#include<stdio.h>
#include<unistd.h>

int main() {
    __pid_t pid = fork();

    if(pid == 0) {
        printf("I am the child process \n");
        printf("PID child : %d \n", getpid());
        printf("PPID child : %d \n", getppid());
    } else {
        printf("I am the parent process \n");
        printf("PID parent : %d \n", getpid());
    }




    return 0;
}