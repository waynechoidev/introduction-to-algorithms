#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void countingSort(int arr[], int size, int exp)
{
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
        output[count[(arr[i] / exp) % 10]-- - 1] = arr[i];

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int size)
{

    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, size, exp);
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 11112, 66};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);
    radixSort(arr, size);
    printArray(arr, size);

    return 0;
}
