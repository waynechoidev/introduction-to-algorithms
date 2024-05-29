#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int cutRod(int *price, int n, int *r)
{
    if (n == 0)
        return 0;

    if (r[n] >= 0)
        return r[n];

    int max_val = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int current_val = price[i] + cutRod(price, n - i, r);
        if (current_val > max_val)
            max_val = current_val;
    }

    r[n] = max_val;
    return max_val;
}

int main()
{
    int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30,
                   32, 35, 37, 40, 45, 50, 55, 60, 65, 70,
                   75, 80, 85, 90, 95, 100, 105, 110, 115};
    int size = sizeof(price) / sizeof(int) - 1;
    int r[size + 1];

    for (int i = 0; i < size + 1; i++)
        r[i] = INT_MIN;

    clock_t start = clock();

    printf("%d\n", cutRod(price, size, r));

    clock_t end = clock();
    printf("it took %f ms\n", ((float)(end - start)) / (CLOCKS_PER_SEC / 1000.0));

    return 0;
}