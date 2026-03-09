#include<stdio.h>
#include<unistd.h>

int main() {
    fork();
    fork();
    fork();

    printf("PID : %d \n PPID : %d \n" , getpid() , getppid());
    return 0;
}