#include<stdio.h>
#include<stdlib.h>


void swap(int arr[] , int i , int j) {
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void insertion_sort(int arr[] , int size) {
	for(int i = 1 ; i < size ; i++) {
		int key = arr[i]; //save the current value
		int j = i-1; // start looking from the index before the index of the current value
		while(j >= 0 && arr[j] > key) { // do the shifting
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key; //a[j] is no longer greater than the key and we shifted so we put it after it
	}
}


void print_array(int arr[] , int size) {
	for(int i = 0 ; i < size ; i ++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(void) {
	int arr[] = {8,4,9,5,7,6,3,2};
	int size = sizeof(arr) / sizeof(arr[0]);
	print_array(arr,size);
	insertion_sort(arr,size);
	print_array(arr,size);
	return 0;
}
