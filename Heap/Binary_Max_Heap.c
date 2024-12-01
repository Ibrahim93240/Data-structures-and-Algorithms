#include <stdio.h>

#define MAX_HEAP_SIZE 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{

    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

void printHeap(int arr[], int n)
{
    printf("Max Heap array representation:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[MAX_HEAP_SIZE];
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    buildMaxHeap(arr, n);

    printf("Max Heap:\n");
    printHeap(arr, n);

    return 0;
}
