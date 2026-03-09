#include<stdio.h>
#include<unistd.h>

int main() {

    printf("Before exec \n");
    execl("/bin/ls", "ls" , "-1",NULL);
    printf("After exec \n");
    return 0;
}