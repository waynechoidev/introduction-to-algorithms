#include <stdio.h>

void insertionSortDecrease(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[] = {12, 5, 7, 3, 9};
    printArr(arr, 5);

    insertionSortDecrease(arr, 5);
    printArr(arr, 5);

    return 0;
}