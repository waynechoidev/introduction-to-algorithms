#include <stdio.h>

int fibonacciNumbers(int n)
{
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return fibonacciNumbers(n-1) + fibonacciNumbers(n-2);
}

int main()
{
    for(int i = 1; i <= 10; i++)
    {
        printf("%d ", fibonacciNumbers(i));
    }

    return 0;
}