#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Heap
{
    int *data;
    int size;
    int capacity;
} Heap;

// int parent(int i)
// {
//     if (i == 0)
//         return -1;
//     return (i - 1) / 2;
// }

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// void printHeap(Heap *heap)
// {
//     int height = ceil(log2(heap->size + 1));
//     int index = 0;
//     for (int level = 0; level < height; level++)
//     {
//         int numOfNodes = pow(2, level);
//         int spaces = pow(2, height - level) - 1;

//         for (int i = 0; i < spaces; i++)
//         {
//             printf(" ");
//         }

//         for (int i = 0; i < numOfNodes && index < heap->size; i++)
//         {
//             printf("%2d", heap->data[index++]);

//             int distance = pow(2, height - level + 1) - 1;

//             if (i < numOfNodes - 1)
//             {
//                 for (int j = 0; j < distance - 1; j++)
//                 {
//                     printf(" ");
//                 }
//             }
//         }
//         printf("\n");
//     }
// }

void maxHeapifyDown(Heap *heap, int i)
{
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < heap->size && heap->data[l] > heap->data[i])
        largest = l;
    else
        largest = i;
    if (r < heap->size && heap->data[r] > heap->data[largest])
        largest = r;
    if (largest != i)
    {
        swap(heap->data, i, largest);
        maxHeapifyDown(heap, largest);
    }
}

// void maxHeapifyUp(Heap *heap, int i)
// {
//     int p = parent(i);
//     if (p == -1)
//         return;
//     int largest;
//     if (p >= 0 && heap->data[p] > heap->data[i])
//         largest = p;
//     else
//         largest = i;
//     if (largest == i)
//     {
//         swap(heap->data, i, p);
//         maxHeapifyUp(heap, p);
//     }
// }

Heap *createHeap(int *data, int size, int capacity)
{
    Heap *res = (Heap *)malloc(sizeof(Heap));
    res->data = (int *)malloc(sizeof(int) * capacity);
    memcpy(res->data, data, size * sizeof(int));
    res->capacity = capacity;
    res->size = size;

    for (int i = res->size / 2; i >= 0; i--)
        maxHeapifyDown(res, i);

    return res;
}

int pop(Heap *heap)
{
    int res = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    maxHeapifyDown(heap, 0);
    return res;
}

// void push(Heap *heap, int n)
// {
//     heap->data[heap->size++] = n;
//     maxHeapifyUp(heap, heap->size - 1);
// }

void heapSort(int *arr, int size)
{
    Heap *heap = createHeap(arr, size, size);
    for (int i = size - 1; i >= 0; i--)
        arr[i] = pop(heap);
    free(heap->data);
    free(heap);
}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    printf("input: ");
    printArr(arr, 10);

    heapSort(arr, 10);
    printf("output: ");
    printArr(arr, 10);

    return 0;
}
