#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

/*
 typedef struct Queue {
 QNode * front;
 QNode * rear;
}Queue;
for this you just take Queue * Q and edit it as Q->front and Q-> rear and pass & Q
*/
typedef struct SNode {
	char data;
	struct SNode * next;
} SNode;

typedef struct QNode {
	char data;
	struct QNode * next;
} QNode;

SNode * push(SNode * stack_top , char ch) {
	SNode * new  = malloc(sizeof(*new));
	new-> data = ch;
	new->next = NULL;
	if(stack_top == NULL) return new;
	
	new->next = stack_top;
	return new;
} 

char pop(SNode ** stack_top) {
	char ch = (*stack_top)->data;
	(*stack_top) = (*stack_top)->next;
	return ch;
}


void enqueue(QNode ** Qfront , QNode ** Qrear , char ch) {
	QNode * new = malloc(sizeof(*new));
	new-> data = ch;
	new-> next = NULL;
	
	if(*Qfront == NULL) {
		*Qfront = *Qrear = new;
		return;
	}
	// the only line needed to be added
	(*Qrear)-> next = new;
	(*Qrear) = new;  
}


/*
void enqueue(QNode ** Qfront , char ch) {
	QNode * new = malloc(sizeof(*new));
	new->data = ch;
	new->next = NULL;
	if((*Qfront) == NULL) {
		(*Qfront) = new;
		return;
	}
	QNode * temp = (*Qfront);
	while(temp ->next != NULL) {
		temp = temp->next;
	}
	temp ->next = new;
	return;
}
*/
char dequeue(QNode ** Qfront) {
	char ch = (*Qfront)->data;
	(*Qfront) = (*Qfront)->next;
	return ch;
}


int main(void) {
	
	char str[100];
	int size = 0;
	int is_palind = 1;
	printf("Enter a line : ");
	scanf("%s" , str);
	while(str[size] != '\0') size++;
	SNode * stack_top = NULL;
	QNode * Qfront = NULL;
	QNode * Qrear = NULL;
	for(int i =  0 ; i < size ; i++) {
		str[i] = toupper(str[i]);
	}
	for(int i = 0 ; i < size ; i++) {
		stack_top = push(stack_top , str[i]);
		enqueue(&Qfront , &Qrear , str[i]);
	}
	
	for(int i = 0  ; i < size ; i++) {
		char f = pop(&stack_top);
		char l = dequeue(&Qfront);
		if(f != l) {
			is_palind = 0;
			break;
		}
	}
	if(is_palind) {
		printf("The line is palindrome \n");
	} else {
		printf("The line is not palindrome \n");
	}

	
	
	return 0;
}
