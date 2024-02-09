#include <stdio.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
        {
            if(arr[min] > arr[j]) min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr[] = {12, 5, 7, 3, 9};
    printArr(arr, 5);

    selectionSort(arr, 5);
    printArr(arr, 5);

    return 0;
}