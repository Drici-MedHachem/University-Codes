#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>




int main(void) {
	char str[] = "Chabiba we are doing good";
	int len = 0;
	while(str[len] != '\0') len++;
	int size = strlen(str);
	printf("%d \n",size);
	printf("%d \n",len);
	return 0;
}
