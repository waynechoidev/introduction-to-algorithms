#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int *arr, int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
        if (arr[j] <= x)
            swap(arr, ++i, j);
    swap(arr, i + 1, r);
    return i + 1;
}

void quickSort(int *arr, int p, int r)
{
    while (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        p = q + 1;
    }
}

int main()
{
    int arr[8] = {2, 8, 7, 1, 3, 5, 6, 4};
    printArr(arr, 8);
    quickSort(arr, 0, 7);
    printArr(arr, 8);

    return 0;
}