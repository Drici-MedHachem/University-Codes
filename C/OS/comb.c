#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
__pid_t pid = fork();
if (pid == 0) {
execl("/bin/date", "date", NULL);
sleep(60);
} else {
wait(NULL);
printf("Command terminated\n");
sleep(60);
}
return 0;
}