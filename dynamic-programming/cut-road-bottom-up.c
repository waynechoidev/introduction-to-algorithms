#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int cutRod(int *price, int n)
{
    int r[n + 1];

    r[0] = 0;

    for (int j = 1; j <= n; ++j)
    {
        int max_val = INT_MIN;
        for (int i = 1; i <= j; ++i)
        {
            int current_val = price[i] + r[j - i];
            if (current_val > max_val)
                max_val = current_val;
        }

        r[j] = max_val;
    }

    return r[n];
}

int main()
{
    int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30,
                   32, 35, 37, 40, 45, 50, 55, 60, 65, 70,
                   75, 80, 85, 90, 95, 100, 105, 110, 115};
    int size = sizeof(price) / sizeof(int) - 1;

    clock_t start = clock();

    printf("%d\n", cutRod(price, size));

    clock_t end = clock();
    printf("it took %f ms\n", ((float)(end - start)) / (CLOCKS_PER_SEC / 1000.0));

    return 0;
}