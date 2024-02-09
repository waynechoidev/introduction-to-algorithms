#include <stdio.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int *arr, int p, int q, int r)
{
    int leftLength = q - p + 1;
    int rightLength = r - q;

    int left[leftLength];
    int right[rightLength];

    for (int i = 0; i < leftLength; i++)
        left[i] = arr[i + p];
    for (int i = 0; i < rightLength; i++)
        right[i] = arr[i + q + 1];

    int i = 0; // for left
    int j = 0; // for right
    int k = p; // for arr

    while(i < leftLength && j < rightLength)
    {
        if(left[i] < right[j]) arr[k++] = left[i++];
        else arr[k++] = right [j++];
    }

    while(i < leftLength) arr[k++] = left[i++];
    while(j < rightLength) arr[k++] = right[j++];
}

void mergeSort(int *arr, int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);

        merge(arr, p, q, r);
    }
}

int main()
{
    int arr[] = {12, 5, 7, 3, 4, 20, 9, 57, 29};
    printArr(arr, 9);

    int temp[] = {5, 12, 3, 7};
    merge(temp, 0, 1, 3);

    mergeSort(arr, 0, 8);
    printArr(arr, 9);

    return 0;
}