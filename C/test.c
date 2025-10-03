
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>




int main(void) {
	int a = 5;
	int *p = &a;
	int ** pp = &p;
	printf("%p \n",p);
	printf("%p \n",&a);
	return 0;
}
