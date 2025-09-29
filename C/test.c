
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef struct node * {
	int key;
	struct node * next;
}node;


static node * head , z;

void init_list(void) {
	head = malloc(sizeof(*head));
	z = malloc(sizeof(*z));
	head-> key = 0;
	head-> next = z;
	z-> next = z;
}

void inset_after(int key_, node * t) {
	node * x = malloc(sizeof(*x));
	x->next = t-> next;
	t-> next = x;
	x-> key = key_;
}

void remove_after(node* t) {
	node * x;
	x = t->next;
	t->next = t->next->next;
	free(x);
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


int main(void) {
	
}
