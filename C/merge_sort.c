#include <stdio.h>

// Function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int i = left;       // index for left subarray
    int j = mid + 1;    // index for right subarray
    int k = 0;          // index for temporary array

    int temp[right - left + 1];

    // Merge both halves into temp[]
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements of left half
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right half
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy temp back to original array
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

// Recursive merge sort function
void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return; // base case
    }

    int mid = left + (right - left) / 2;

    // Recursively sort left half
    mergeSort(arr, left, mid);

    // Recursively sort right half
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

// Helper function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printArray(arr, n);
    return 0;
}
