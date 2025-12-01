#include<stdio.h>
#include<stdlib.h>

void swap(int arr[] ,int i,int j) {
	int t;
	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
	return;
}

void bubble_sort(int arr[], int size) {
	for(int i = 0 ; i < size - 1 ; i++) {
		int done = 1;
		for(int j = 0 ; j < size-1-i ; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr,j,j+1);
				done = 0;
			}
		}
		if(done) break; //if in this iteration there were no swapping made then the array is sorted
		
	}
}

int main(void) {
	
	
	
	return 0;
}
