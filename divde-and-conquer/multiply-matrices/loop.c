#include <stdio.h>
#include <stdlib.h>

void printMatrices(int** mat, int size)
{
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int** allocateMatrix(int size)
{
    int** mat = (int**)malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++)
        mat[i] = (int*)malloc(sizeof(int) * size);
    return mat;
}

void delocateMatrix(int** mat, int size)
{
    for(int i = 0; i < size; i++)
        free(mat[i]);
    free(mat);
}

void multiplyMatrices(int **A, int **B, int **res, int size)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            for(int k = 0; k < size; k++)
                res[i][j] = res[i][j] + A[i][k] * B[k][j];
}

int main() {
    const int size = 4;

    int** A = allocateMatrix(size);
    A[0][0] = 2; A[0][1] = 5; A[0][2] = 3; A[0][3] = 6;
    A[1][0] = 1; A[1][1] = 7; A[1][2] = 4; A[1][3] = 7;
    A[2][0] = 6; A[2][1] = 9; A[2][2] = 8; A[2][3] = 2;
    A[3][0] = 3; A[3][1] = 5; A[3][2] = 7; A[3][3] = 1;

    int** B = allocateMatrix(size);
    B[0][0] = 4; B[0][1] = 8; B[0][2] = 2; B[0][3] = 8;
    B[1][0] = 6; B[1][1] = 3; B[1][2] = 1; B[1][3] = 9;
    B[2][0] = 5; B[2][1] = 4; B[2][2] = 7; B[2][3] = 1;
    B[3][0] = 4; B[3][1] = 2; B[3][2] = 6; B[3][3] = 2;

    int** res = allocateMatrix(size);

    multiplyMatrices(A, B, res, size);
 
    printf("Res: \n");
    printMatrices(res, size);
    // 77 55 66 76 
    // 94 59 79 89 
    // 126 111 89 141 
    // 81 69 66 78 

    delocateMatrix(A, size);
    delocateMatrix(B, size);
    delocateMatrix(res, size);

    return 0;
}
