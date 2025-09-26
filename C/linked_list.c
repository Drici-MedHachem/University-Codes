#include<stdio.h>
#include<stdio.h>

typedef struct node {
	int val;
	struct node* next;
}node;


int main(void) {
	node head;
	head.val = 5;
	printf("%d \n",head.val);
	return 0;
}
