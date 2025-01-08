#include <stdio.h>

// Function to merge two sorted arrays
void mergeArrays(int arr1[], int m, int arr2[], int n, int arr3[]) {
    int i = 0, j = 0, k = 0;

    // Merge smaller elements first
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1[], if any
    while (i < m) {
        arr3[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2[], if any
    while (j < n) {
        arr3[k++] = arr2[j++];
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program
int main() {
    int arr1[] = {1, 3, 5, 7};
    int m = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int n = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[m + n];
    mergeArrays(arr1, m, arr2, n, arr3);

    printf("Array 1: ");
    printArray(arr1, m);

    printf("Array 2: ");
    printArray(arr2, n);

    printf("Merged Array: ");
    printArray(arr3, m + n);

    return 0;
}
