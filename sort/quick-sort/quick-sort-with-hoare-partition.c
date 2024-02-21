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
    int x = arr[p];
    int i = p;
    int j = r;
    while (1)
    {
        while (arr[j] > x)
            j--;
        while (arr[i] < x)
            i++;
        if (i < j)
            swap(arr, i, j);
        else
            return j;
    }
}

void quickSort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
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