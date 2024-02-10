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

void multiplyMatrices(int** A, int** B, int** C, int size)
{
    // Base case
    if(size == 1)
    {
        C[0][0] = C[0][0] + A[0][0] * B[0][0];
        return;
    }
    // Divide
    int newSize = size/2;
    int** A11 = allocateMatrix(newSize);
    int** A12 = allocateMatrix(newSize);
    int** A21 = allocateMatrix(newSize);
    int** A22 = allocateMatrix(newSize);
    int** B11 = allocateMatrix(newSize);
    int** B12 = allocateMatrix(newSize);
    int** B21 = allocateMatrix(newSize);
    int** B22 = allocateMatrix(newSize);
    int** C11 = allocateMatrix(newSize);
    int** C12 = allocateMatrix(newSize);
    int** C21 = allocateMatrix(newSize);
    int** C22 = allocateMatrix(newSize);

    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];

            C11[i][j] = 0;
            C12[i][j] = 0;
            C21[i][j] = 0;
            C22[i][j] = 0;
        }
    }

    multiplyMatrices(A11, B11, C11, newSize);
    multiplyMatrices(A12, B21, C11, newSize);
    multiplyMatrices(A11, B12, C12, newSize);
    multiplyMatrices(A12, B22, C12, newSize);
    multiplyMatrices(A21, B11, C21, newSize);
    multiplyMatrices(A22, B21, C21, newSize);
    multiplyMatrices(A21, B12, C22, newSize);
    multiplyMatrices(A22, B22, C22, newSize);

    // Combine
    for(int i = 0; i < newSize; i++)
        for(int j = 0; j < newSize; j++)
        {
            C[i][j] = C[i][j] + C11[i][j];
            C[i][j+newSize] = C[i][j+newSize] + C12[i][j];
            C[i+newSize][j] = C[i+newSize][j] + C21[i][j];
            C[i+newSize][j+newSize] = C[i+newSize][j+newSize] + C22[i][j];
        }
    
    // Free temp matrices    
    delocateMatrix(A11, newSize);
    delocateMatrix(A12, newSize);
    delocateMatrix(A21, newSize);
    delocateMatrix(A22, newSize);
    delocateMatrix(B11, newSize);
    delocateMatrix(B12, newSize);
    delocateMatrix(B21, newSize);
    delocateMatrix(B22, newSize);
    delocateMatrix(C11, newSize);
    delocateMatrix(C12, newSize);
    delocateMatrix(C21, newSize);
    delocateMatrix(C22, newSize);
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

    printf("A: \n");
    printMatrices(A, size);

    printf("B: \n");
    printMatrices(B, size);

    printf("res: \n");
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
