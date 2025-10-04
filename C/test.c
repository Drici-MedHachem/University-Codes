
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>




int main(void) {
	int mat[5][6];
	int i,j;
	int val = 0;
	for(i = 0 ; i < 5 ; i++) {
		for( j = 0 ; j < 6 ; j++) {
			mat[i][j] = val++;
		}
	}
	
	int *pptr = (int*) mat;
	for(i = 0 ; i < 5 ; i++) {
		for( j = 0 ; j < 6 ; j++) {
			printf("%d ",mat[i][j]);
		}
		putchar('\n');
	}
	
	for(i = 0 ; i < 5*6 ; i++) {
		printf("%d ", pptr[i]);
	}
	return 0;
}
