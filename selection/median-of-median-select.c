#include <stdio.h>

int select(int *arr, int p, int r, int i);
int partition(int *arr, int p, int r, int x);
int medianOfMedians(int *arr, int p, int r);

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int medianOfMedians(int *arr, int p, int r)
{
    int n = r - p + 1;
    int groups = (n + 4) / 5;
    int medians[groups];

    for (int j = 0; j < groups; j++)
    {
        int groupStart = p + j * 5;
        int groupEnd = groupStart + 4;
        if (groupEnd > r)
            groupEnd = r;

        for (int k = groupStart + 1; k <= groupEnd; k++)
        {
            int key = arr[k];
            int i = k - 1;
            while (i >= groupStart && arr[i] > key)
            {
                arr[i + 1] = arr[i];
                i--;
            }
            arr[i + 1] = key;
        }

        medians[j] = arr[(groupStart + groupEnd) / 2];
    }

    return select(medians, 0, groups - 1, groups / 2);
}

int select(int *arr, int p, int r, int i)
{
    if (p == r)
        return arr[p];
    int x = medianOfMedians(arr, p, r);
    int q = partition(arr, p, r, x);
    int k = q - p + 1;

    if (i == k)
    {
        return arr[q];
    }
    else if (i < k)
    {
        return select(arr, p, q - 1, i);
    }
    else
    {
        return select(arr, q + 1, r, i - k);
    }
}

int partition(int *arr, int p, int r, int x)
{
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] == x)
        {
            int temp = arr[j];
            arr[j] = arr[r];
            arr[r] = temp;
        }
        if (arr[j] <= x)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

int main()
{
    int arr[8] = {2, 8, 7, 9, 3, 5, 6, 4};
    int i = 4;
    printArr(arr, 8);
    printf("i: %d\n", i);
    printf("res: %d\n", select(arr, 0, 7, 4));

    return 0;
}
