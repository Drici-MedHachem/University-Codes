#include<stdio.h>
#inlucde<stdlib.h>

typedef struct node* {
	int key;
	struct node * next;
}node;

static node * head , *tail, *z , *t;


void initqueue() {
	head = malloc(sizeof(*head));
	z = malloc(sizeof(*z));
	head->key = 0;
	head->next = z;
	z-> next = z;
	tail = head;
}


void insert(int key_) {
	node * t = malloc(sizeof(*t));
	t->key = key_;
	t-> next = z;
	tail-> next = t;
	tail = t;
	
}

 int remove(void) {
	 int x;
	 t = malloc(sizeof(*t));
	 t = head-> next
	 x = t-> key;
	 head-> next = head->next->next;
	 
	 if(t == tail) {
		 tail = head;
	 } 
	 
	 free(t);
	return x;
}

int isempty(void) {
	return tail == head;
}

void free(void) {
	while(!isempty) {
		remove;
	}
}
