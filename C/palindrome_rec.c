
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>


int left = 0;
int right;

int is_pali(char str[], int left , int right) {
	if(left >= right) return 1;
	if(str[left] != str[right]) return 0;
	return  is_pali(str , left + 1,right -1);
}
