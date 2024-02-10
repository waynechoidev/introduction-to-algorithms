#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int* addBinaryInt(int A[], int B[], int n)
{
    int* C = malloc(sizeof(int) * (n + 1));
    int carry = 0;

    for (int i = n - 1; i >= 0; i--) {
        int total = A[i] + B[i] + carry;

        C[i + 1] = total % 2;
        carry = total / 2;
    }

    C[0] = carry;

    return C;
}

int main()
{
    int A[] = {1,0,1};
    int B[] = {0,1,1};
    int n = 3;

    printArr(addBinaryInt(A, B, n), n + 1);
    // 1 0 0 0

    return 0;
}