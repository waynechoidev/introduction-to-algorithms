#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct List
{
    Node *nill;
} List;

List *createList()
{
    List *newList = (List *)malloc(sizeof(List));
    Node *sentinel = (Node *)malloc(sizeof(Node));
    sentinel->data = 0;
    sentinel->next = sentinel->prev = sentinel;
    newList->nill = sentinel;
    return newList;
}

Node *search(List *list, int k)
{
    Node *x = list->nill->next;
    Node *res = NULL;
    while (x != list->nill)
    {
        if (x->data == k)
            res = x;
        x = x->next;
    }
    return res;
}

void prepend(List *list, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->prev = list->nill;
    newNode->next = list->nill->next;
    newNode->data = x;
    list->nill->next = newNode;
    if (list->nill->prev == list->nill)
        list->nill->prev = newNode;
}

void append(List *list, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->prev = list->nill->prev;
    newNode->next = list->nill;
    newNode->data = x;
    list->nill->prev->next = newNode;
    list->nill->prev = newNode;
}

void delete(List *list, int x)
{
    Node *t = search(list, x);
    if (t == NULL)
        return;

    t->prev->next = t->next;
    t->next->prev = t->prev;

    free(t);
}

void print(List *list)
{
    Node *p = list->nill->next;
    while (p != list->nill)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    List *list = createList();
    prepend(list, 3);
    prepend(list, 4);
    prepend(list, 5);
    append(list, 6);
    append(list, 7);
    append(list, 8);

    print(list);

    delete (list, 6);

    print(list);

    return 0;
}