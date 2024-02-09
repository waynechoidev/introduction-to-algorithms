#include <stdio.h>

int linearSearch(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == key) return i;
    }
    return -1;
}

int main()
{
    int arr[] = {12, 5, 7, 3, 9};

    printf("%d\n", linearSearch(arr, 5, 7));
    printf("%d\n", linearSearch(arr, 5, 8));

    return 0;
}