#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 5

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int *countingSort(int *arr, int size)
{
    int count[MAX + 1] = {0};
    int *res = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
        count[arr[i]]++;

    for (int i = 1; i <= MAX; i++)
        count[i] = count[i] + count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        res[count[arr[i]]-- - 1] = arr[i];
    }

    return res;
}

int main()
{
    int arr[10] = {1, 5, 4, 0, 3, 4, 1, 2, 1, 3};

    printArray(arr, 10);

    int *sortedArr = countingSort(arr, 10);
    printArray(sortedArr, 10);

    free(sortedArr);

    return 0;
}