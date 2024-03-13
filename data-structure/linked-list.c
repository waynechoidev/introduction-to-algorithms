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
    Node *head;
} List;

List *createList()
{
    List *newList = (List *)malloc(sizeof(List));
    newList->head = NULL;
    return newList;
}

Node *search(List *list, int k)
{
    Node *x = list->head;
    while (x != NULL && x->data != k)
        x = x->next;
    return x;
}

void prepend(List *list, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->prev = NULL;
    if (list->head == NULL)
    {
        newNode->next = NULL;
        list->head = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void append(List *list, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    if (list->head == NULL)
    {
        newNode->prev = NULL;
        list->head = newNode;
    }
    else
    {
        Node *p = list->head;
        while (p->next != NULL)
            p = p->next;
        p->next = newNode;
        newNode->prev = p;
    }
}

void delete(List *list, int x)
{
    Node *t = search(list, x);
    if (t == NULL)
        return;

    if (t == list->head)
    {
        list->head = t->next;
        t->next->prev = NULL;
    }
    else if (t->next == NULL)
    {
        t->prev->next = NULL;
    }
    else
    {
        t->prev->next = t->next;
        t->next->prev = t->prev;
    }
    free(t);
}

void print(List *list)
{
    Node *p = list->head;
    while (p != NULL)
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