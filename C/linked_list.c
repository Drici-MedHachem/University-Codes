#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int key;
	struct node * next;
}node;

node * initlist(void+) {
	node * head = malloc(sizeof(*head));
	node * z malloc(sizeof(*z));
	head-> next = z;
	z->next = z;
	return head;
}

void del_next(node * t) {
	t->next = t-> next-> next
}

void insert_after(node * t,int key_) {
	node * x = malloc(*x);
	x-> key = key_;
	x-> next = t->next;
	t-> next = x;
}
/*
 * to implement a circular linked list all you need to do is to first create a core
 * node x and then create a pointer t that points to it and each time create a next 
 * pointer to t , move to it and put the key depending on how many nodes you got
 * once this is done put the next of the last t back to the core x 
 */ 

int main(void) {
	
	return 0;
}
