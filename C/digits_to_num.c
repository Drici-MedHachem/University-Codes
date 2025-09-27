#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int * digits = malloc(n * sizeof(*digits));
	int res = 0;
	for(int i = 0 ; i < n ; i ++) {
		scanf("%d",&digits[i]);
		res = 10 * res + digits[i];
	}
	for(int i = 0 ; i < n ; i++) {
		printf("digit %d = %d \n",i,digits[i]);
	}
	printf("%d \n",res);
	
	return 0;
}
