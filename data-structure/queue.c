#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int *data;
    int maxSize;
    int curSize;
    int head;
    int tail;
} Queue;

Queue *createQueue(int size)
{
    Queue *res = (Queue *)malloc(sizeof(Queue));
    res->data = (int *)malloc(sizeof(int) * size);
    res->head = res->tail = size / 2;
    res->curSize = 0;
    res->maxSize = size;
    return res;
}

bool queueEmpty(Queue *q)
{
    return q->head == q->tail;
}

bool queueFull(Queue *q)
{
    return q->curSize == q->maxSize;
}

void enqueue(Queue *q, int x)
{
    if (queueFull(q))
    {
        printf("The queue is full \n");
        return;
    }

    q->data[q->tail] = x;
    q->curSize++;

    if (q->tail == q->maxSize - 1)
        q->tail = 0;
    else
        q->tail++;
}

int dequeue(Queue *q)
{
    if (queueEmpty(q))
    {
        printf("The queue is empty \n");
        return -1;
    }

    int res = q->data[q->head];
    q->curSize--;

    if (q->head == q->maxSize - 1)
        q->head = 0;
    else
        q->head++;

    return res;
}

int main()
{
    Queue *q = createQueue(12);

    enqueue(q, 15);
    enqueue(q, 6);
    enqueue(q, 9);
    enqueue(q, 8);
    enqueue(q, 4);
    enqueue(q, 17);
    enqueue(q, 3);
    enqueue(q, 5);

    for (int i = 0; i < q->maxSize; i++)
        printf("%d ", q->data[i]);
    printf("\n");

    printf("dequeue: %d\n", dequeue(q));
    printf("dequeue: %d\n", dequeue(q));
    printf("dequeue: %d\n", dequeue(q));
    printf("dequeue: %d\n", dequeue(q));
    printf("dequeue: %d\n", dequeue(q));
    printf("dequeue: %d\n", dequeue(q));
    printf("dequeue: %d\n", dequeue(q));
    printf("dequeue: %d\n", dequeue(q));

    return 0;
}