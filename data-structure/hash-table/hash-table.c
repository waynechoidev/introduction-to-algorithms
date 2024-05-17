#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define SEED 15412345
#define MAX_KEY_LENGTH 20

typedef struct HashNode
{
    char key[MAX_KEY_LENGTH];
    int value;
} HashNode;

typedef struct ListNode
{
    HashNode *data;
    struct ListNode *next;
} ListNode;

unsigned int hash(char *key)
{
    unsigned int len = strlen(key);
    unsigned int hash_value = 0;
    for (int i = 0; i < len; i++)
    {
        hash_value += key[i];
    }
    srand(SEED);
    return (unsigned int)(hash_value * rand()) % TABLE_SIZE;
}

void insert(ListNode **table, char *key, int value)
{
    HashNode *newData = (HashNode *)malloc(sizeof(HashNode));
    strcpy(newData->key, key);
    newData->value = value;

    unsigned int index = hash(key);

    ListNode *newListItem = (ListNode *)malloc(sizeof(ListNode));
    newListItem->data = newData;
    newListItem->next = NULL;

    if (table[index] == NULL)
        table[index] = newListItem;

    else
    {
        ListNode *pointer = table[index];

        while (pointer->next != NULL)
            pointer = pointer->next;

        pointer->next = newListItem;
    }
}

int search(ListNode **table, char *key)
{
    unsigned int index = hash(key);
    if (table[index] != NULL)
    {
        ListNode *pointer = table[index];

        while (strcmp(pointer->data->key, key) != 0)
            pointer = pointer->next;

        if (strcmp(pointer->data->key, key) == 0)
            return pointer->data->value;

        else

            return -1;
    }
    else
        return -1;
}

void delete(ListNode **table, char *key)
{
    unsigned int index = hash(key);
    if (table[index] != NULL)
    {
        ListNode *current = table[index];
        ListNode *prev = NULL;

        while (current != NULL && strcmp(current->data->key, key) != 0)
        {
            prev = current;
            current = current->next;
        }

        if (current != NULL && strcmp(current->data->key, key) == 0)
        {

            if (prev != NULL)
            {
                prev->next = current->next;
            }
            else
            {

                table[index] = current->next;
            }

            free(current->data);
            free(current);
            printf("Item with key '%s' deleted.\n", key);
        }
        else
        {
            printf("Item with key '%s' not found.\n", key);
        }
    }
    else
    {
        printf("Item with key '%s' not found.\n", key);
    }
}

int main()
{
    ListNode *table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }

    insert(table, "Mon", 1);
    insert(table, "Tue", 2);
    insert(table, "Wed", 3);
    insert(table, "Thur", 4);
    insert(table, "Fri", 5);
    insert(table, "Sat", 6);
    insert(table, "Sun", 7);

    printf("%d\n", search(table, "Mon"));
    printf("%d\n", search(table, "Tue"));
    printf("%d\n", search(table, "Wed"));
    printf("%d\n", search(table, "Thur"));
    printf("%d\n", search(table, "Fri"));
    printf("%d\n", search(table, "Sat"));
    printf("%d\n", search(table, "Sun"));
    printf("%d\n", search(table, "Sunfdafs"));

    delete (table, "Sunaaa");
    delete (table, "Sun");
    delete (table, "Wed");
}