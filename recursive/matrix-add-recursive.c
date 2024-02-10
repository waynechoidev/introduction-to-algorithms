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

void addMatrices(int **A, int **B, int **res, int size, int row, int col)
{
    // Base case
    if(row == size) return;

    res[row][col] = A[row][col] + B[row][col];
    if(col == size) addMatrices(A, B, res, size, row+1, 0);
    else addMatrices(A, B, res, size, row, col+1);
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

    addMatrices(A, B, res, size, 0, 0);
 
    printf("Res: \n");
    printMatrices(res, size);
    // 6 13 5 14 
    // 7 10 5 16 
    // 11 13 15 3 
    // 7 7 13 3 

    delocateMatrix(A, size);
    delocateMatrix(B, size);
    delocateMatrix(res, size);

    return 0;
}
