#include<stdio.h>
#include<stdlib.h>

void swap(int arr[] ,int i,int j) {
	int t;
	t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
	return;
}


void selection_sort(int arr[] , int size) {
	for(int valid_idx = 0 ; valid_idx < size-1 ; valid_idx++) {
		int min_idx = valid_idx;
		for(int i = valid_idx +1  ; i < size ; i++)  {
			if(arr[i] < arr[min_idx]) min_idx = i;
		}
		if(min_idx != valid_idx) swap(arr,min_idx , valid_idx);
	}
}



int main(void) {
	return 0;
}
