#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int key;
	struct node * next;
}node;
static node  * head , *z;
node * init_list(void) {
	head = malloc(sizeof(*head));
	z malloc(sizeof(*z));
	head-> next = z;
	z->next = z;
	return head;
}

void delete_after(node * t) {
	node * x = t->next;
	t->next = t-> next-> next;
	free(x);
}

void insert_after(node * t,int key_) {
	node * x = malloc(*x);
	x-> key = key_;
	x-> next = t->next;
	t-> next = x;
}

void move_next_to_front(node * t) {
	node * x;
	x = t->next;
	t-> next = t->next->next;
	x-> next = head-> next;
	head->next = x;
}

void exchange(node * u , node * v) {
	node * x = u-> next;
	node * y = v-> next;
	u->next = y;
	v->next = x;
	
	node * temp = x-> next;
	x->next = y->next;
	y->next = temp;
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
