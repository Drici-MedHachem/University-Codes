#include<stdio.h>
#include<unistd.h>

int main() {
    __pid_t pid = fork();
    if(pid == 0) {
        printf("Child terminated \n");
        return 0;
    } else {
        sleep(30);
    }
    return 0;
}