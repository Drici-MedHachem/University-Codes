
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>


int left = 0;
int right;

void reverse(char str[]) {
	if(left >= right) {
		return;
	}
	char temp;
	temp = str[left];
	str[left] = str[right];
	str[right] = temp;
	left++;
	right--;
	return reverse(str);
}



int main(void) {
	char str[] = "Hello World!";
		printf("%s \n", str);
	right = sizeof(str)/sizeof(str[0]) - 2;
	reverse(str);
	printf("%s \n",str);
	return 0;
}
