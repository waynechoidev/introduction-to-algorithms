#include <stdio.h>
#include <stdlib.h>

int getRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

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
    int temp = getRandom(p, r);
    swap(arr, r, temp);

    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
        if (arr[j] <= x)
            swap(arr, ++i, j);
    swap(arr, i + 1, r);
    return i + 1;
}

int randomizedSelect(int *arr, int p, int r, int i)
{
    if (p == r)
        return arr[p];
    int q = partition(arr, p, r);
    int k = q - p + 1;
    if (i == k)
        return arr[q];
    else if (i < k)
        return randomizedSelect(arr, p, q - 1, i);
    else
        return randomizedSelect(arr, q + 1, r, i - k);
}

int main()
{
    int arr[8] = {2, 8, 7, 9, 3, 5, 6, 4};
    int i = 4;
    printArr(arr, 8);
    printf("i: %d\n", i);
    printf("res: %d\n", randomizedSelect(arr, 0, 7, 4));

    return 0;
}