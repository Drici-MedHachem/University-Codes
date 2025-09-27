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


int main(void) {
	
	return 0;
}
