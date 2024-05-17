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

typedef struct HashTable
{
    HashNode *data[TABLE_SIZE];
} HashTable;

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

void insert(HashTable *table, char *key, int value)
{
    unsigned int index = hash(key);
    unsigned int original_index = index;

    while (table->data[index] != NULL)
    {
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index)
        {
            printf("Hash table is full.\n");
            return;
        }
    }

    HashNode *newData = (HashNode *)malloc(sizeof(HashNode));
    strcpy(newData->key, key);
    newData->value = value;

    table->data[index] = newData;
}

int search(HashTable *table, char *key)
{
    unsigned int index = hash(key);
    unsigned int original_index = index;

    while (table->data[index] != NULL && strcmp(table->data[index]->key, key) != 0)
    {
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index)
            return -1; // Reached the original index, meaning key doesn't exist
    }

    if (table->data[index] != NULL && strcmp(table->data[index]->key, key) == 0)
        return table->data[index]->value;
    else
        return -1; // Key not found
}

void delete(HashTable *table, char *key)
{
    unsigned int index = hash(key);
    unsigned int original_index = index;

    while (table->data[index] != NULL && strcmp(table->data[index]->key, key) != 0)
    {
        index = (index + 1) % TABLE_SIZE;
        if (index == original_index)
        {
            printf("Item with key '%s' not found.\n", key);
            return;
        }
    }

    if (table->data[index] != NULL && strcmp(table->data[index]->key, key) == 0)
    {
        free(table->data[index]);
        table->data[index] = NULL;
        printf("Item with key '%s' deleted.\n", key);
    }
    else
    {
        printf("Item with key '%s' not found.\n", key);
    }
}

int main()
{
    HashTable table;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table.data[i] = NULL;
    }

    insert(&table, "Mon", 1);
    insert(&table, "Tue", 2);
    insert(&table, "Wed", 3);
    insert(&table, "Thur", 4);
    insert(&table, "Fri", 5);
    insert(&table, "Sat", 6);
    insert(&table, "Sun", 7);

    printf("%d\n", search(&table, "Mon"));
    printf("%d\n", search(&table, "Tue"));
    printf("%d\n", search(&table, "Wed"));
    printf("%d\n", search(&table, "Thur"));
    printf("%d\n", search(&table, "Fri"));
    printf("%d\n", search(&table, "Sat"));
    printf("%d\n", search(&table, "Sun"));
    printf("%d\n", search(&table, "Sunfdafs"));

    delete (&table, "Sunaaa");
    delete (&table, "Sun");
    delete (&table, "Wed");
}
