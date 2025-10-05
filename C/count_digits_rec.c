
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>



int count_digits(int n) {
	if(n / 10 == 0) {
		return 1;
	}
	return 1 + count_digits(n/10);
}
