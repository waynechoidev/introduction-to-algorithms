#include <stdio.h>

#define SIZE 4

void printMatrices(int mat[SIZE][SIZE])
{
    for(int i = 0; i < SIZE; i++) {
    for(int j = 0; j < SIZE; j++) {
        printf("%d ", mat[i][j]);
    }
    printf("\n");
    }
}

void multiplyMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int res[SIZE][SIZE])
{
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            for(int k = 0; k < SIZE; k++)
                res[i][j] = res[i][j] + A[i][k] * B[k][j];
}

int main() {
    int A[SIZE][SIZE] = {
        {2, 5, 3, 6},
        {1, 7, 4, 7},
        {6, 9, 8, 2},
        {3, 5, 7, 1}
    };

    int B[SIZE][SIZE] = {
        {4, 8, 2, 8},
        {6, 3, 1, 9},
        {5, 4, 7, 1},
        {4, 2, 6, 2}
    };

    int res[SIZE][SIZE] = {0};

    multiplyMatrices(A, B, res);
 
    printf("Res: \n");
    printMatrices(res);

    return 0;
}
