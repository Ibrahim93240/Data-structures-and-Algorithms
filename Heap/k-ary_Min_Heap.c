#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to maintain the min-heap property for a k-ary heap
void minHeapify(int arr[], int n, int i, int k) {
    int smallest = i;
    for (int j = 1; j <= k; j++) {
        int child = k * i + j;
        if (child < n && arr[child] < arr[smallest]) {
            smallest = child;
        }
    }
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest, k);
    }
}

// Function to build a min-heap from an array
void buildMinHeap(int arr[], int n, int k) {
    for (int i = (n - 1) / k; i >= 0; i--) {
        minHeapify(arr, n, i, k);
    }
}

// Function to perform heap sort in descending order using a k-ary min-heap
void heapSortDescending(int arr[], int n, int k) {
    buildMinHeap(arr, n, k);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        minHeapify(arr, i, 0, k);
    }

    // Reverse the array to get descending order
    for (int i = 0; i < n / 2; i++) {
        swap(&arr[i], &arr[n - 1 - i]);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, k;

    // Taking input for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamic allocation of array
    int* arr = (int*)malloc(n * sizeof(int));

    // Taking input for the array elements
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking input for the value of k
    printf("Enter the value of k for k-ary heap: ");
    scanf("%d", &k);

    printf("Original array: \n");
    printArray(arr, n);

    heapSortDescending(arr, n, k);

    printf("Sorted array in descending order: \n");
    printArray(arr, n);

    // Freeing the allocated memory
    free(arr);

    return 0;
}
