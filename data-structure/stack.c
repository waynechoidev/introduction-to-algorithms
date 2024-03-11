#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    int *data;
    int size;
    int top;
} Stack;

Stack *createStack(int size)
{
    Stack *res = (Stack *)malloc(sizeof(Stack));
    res->data = (int *)malloc(sizeof(int) * size);
    res->size = size;
    res->top = -1;
}

bool stackEmpty(Stack *stk)
{
    return stk->top < 0;
}

bool stackFull(Stack *stk)
{
    return stk->top >= stk->size;
}

void push(Stack *stk, int x)
{
    if (stackFull(stk))
    {
        printf("The stack is full!\n");
        return;
    }

    stk->data[++(stk->top)] = x;
}

int pop(Stack *stk)
{
    if (stackEmpty(stk))
    {
        printf("The stack is empty!\n");
        return -1;
    }

    return stk->data[(stk->top)--];
}

int main()
{
    Stack *stk = createStack(7);
    push(stk, 15);
    push(stk, 6);
    push(stk, 2);
    push(stk, 9);
    push(stk, 17);
    push(stk, 3);

    printf("pop: %d\n", pop(stk));
    printf("pop: %d\n", pop(stk));
    printf("pop: %d\n", pop(stk));

    return 0;
}