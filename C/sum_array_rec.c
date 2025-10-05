
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>



int sum_array(int arr[] , int size) {
	if(size == 1) {
		return arr[size-1];
	}
	return arr[size-1] + sum_array(arr , size-1);
}
