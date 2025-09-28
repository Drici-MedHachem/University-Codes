#include<stdio.h>
#include<stdlib.h>

typedef static struct node{
	int key;
	struct node * next;
}node;

static node * head , z , t;

void init_stack(void) {
	head = malloc(sizeof(head*));
	z = malloc(sizeof(*z));
	head-> key = 0;
	head-> next = z;
	z->next = z;
}

void push(int v) {
	t = malloc(sizeof(t*));
	t-> key = v;
	t-> next = head-> next;
	head->next = t;
}
int pop() {
	int x;
	t = head->next
	x = t->key
	head->next = t->next;
	return x;
}

int stackisempty() {
	return (head-> next == z);
}
