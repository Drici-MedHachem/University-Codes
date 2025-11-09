#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>


int main(void) {
		int mat[5][5] = {0};
		int * ptr = mat;
		int * _ptr = &mat[0];
		printf("%p \n %p",ptr,_ptr);
		
} 
