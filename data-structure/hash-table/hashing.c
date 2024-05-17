#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define A 0.6180339887
#define MULTIPLIER 2654435761u
#define SEED 15412345

unsigned int divisionMethod(char *key)
{
    unsigned int len = strlen(key);
    unsigned int hash_value = 0;
    for (int i = 0; i < len; i++)
    {
        hash_value += key[i];
    }
    return hash_value % TABLE_SIZE;
}

unsigned int multipicationMethod(char *key)
{
    unsigned int len = strlen(key);
    double hash_value = 0;
    for (int i = 0; i < len; i++)
    {
        hash_value += key[i];
    }
    double kA = hash_value * A;
    double fractional_part = kA - (int)kA;
    return (unsigned int)(TABLE_SIZE * fractional_part);
}

unsigned int multiplyShiftMethod(char *key)
{
    unsigned int len = strlen(key);
    unsigned int hash_value = 0;
    for (int i = 0; i < len; i++)
    {
        hash_value += key[i];
    }
    hash_value *= MULTIPLIER;
    return (hash_value >> (32 - TABLE_SIZE)) % TABLE_SIZE;
}

unsigned int randomHash(char *key)
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

unsigned int hash(char *key)
{
    return multipicationMethod(key);
}

int main()
{
    printf("%d\n", hash("Mon"));
    printf("%d\n", hash("Tue"));
    printf("%d\n", hash("Wed"));
    printf("%d\n", hash("Thur"));
    printf("%d\n", hash("Fri"));
    printf("%d\n", hash("Sat"));
    printf("%d\n", hash("Sun"));
    return 0;
}
