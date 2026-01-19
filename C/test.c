#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef struct node {
	int key;
	struct node * next;
} node;

int main(void) {
	// quick sort
	// reverse linked list
	int n,m;
	scanf("%d %d",&n,&m);
	int ** arr = malloc(n * sizeof(*arr));
	for(int i = 0 ; i < n ; i++) {
		arr[i] = malloc(m * sizeof(**arr));
	}
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			printf("arr[%d][%d] = ",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
	
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
} 
