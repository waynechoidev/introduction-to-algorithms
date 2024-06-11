#include <stdio.h>
#include <string.h>
#define MAX 10

int dpLen[MAX][MAX];
int dpDir[MAX][MAX];

int max(int a, int b) { return a > b ? a : b; }

int lcsBruteForce(char *x, char *y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (x[m - 1] == y[n - 1])
        return 1 + lcsBruteForce(x, y, m - 1, n - 1);
    else
        return max(lcsBruteForce(x, y, m - 1, n), lcsBruteForce(x, y, m, n - 1));
}

int lcsDP(char *x, char *y, int dpLen[MAX][MAX], int dpDir[MAX][MAX])
{
    for (int i = 1; i <= strlen(x); ++i)
        for (int j = 1; j <= strlen(y); ++j)
            if (x[i - 1] == y[j - 1])
            {
                dpLen[i][j] = dpLen[i - 1][j - 1] + 1;
                dpDir[i][j] = 1; // left diagonal
            }
            else if (dpLen[i - 1][j] >= dpLen[i][j - 1])
            {
                dpLen[i][j] = dpLen[i - 1][j];
                dpDir[i][j] = 2; // up
            }
            else
            {
                dpLen[i][j] = dpLen[i][j - 1];
                dpDir[i][j] = 3; // left
            }

    return dpLen[strlen(x)][strlen(y)];
}

void printLcs(int dpDir[MAX][MAX], char *x, int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (dpDir[i][j] == 1)
    {
        printLcs(dpDir, x, i - 1, j - 1);
        printf("%c", x[i - 1]);
    }
    else if (dpDir[i][j] == 2)
        printLcs(dpDir, x, i - 1, j);
    else
        printLcs(dpDir, x, i, j - 1);
}

int main()
{
    char *s1 = "ABCBDAB";
    char *s2 = "BDCABA";

    printf("Brute Force: %d\n", lcsBruteForce(s1, s2, strlen(s1), strlen(s2)));

    printf("DP: %d\n", lcsDP(s1, s2, dpLen, dpDir));
    printLcs(dpDir, s1, strlen(s1), strlen(s2));

    return 0;
}