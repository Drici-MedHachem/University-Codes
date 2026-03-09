#include<stdio.h>
#include<unistd.h>

int main() {
    __pid_t pid = fork();
    if(pid > 0) {
        printf("Parent PPID : %d \n" , getpid());
        printf("Parent terminated \n");
        return 0;
    } else {
        sleep(10);
        printf("Child new PPID : %d \n",  getppid());
    }

    return 0;
}