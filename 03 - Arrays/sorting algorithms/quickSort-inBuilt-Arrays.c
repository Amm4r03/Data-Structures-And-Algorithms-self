#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main()
{
    srand(time(NULL));
    printf("current array : \n");
    int array[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++)
    {
        array[i] = rand() % 1000;
    }

    for(int i = 0; i < MAX_SIZE;i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    qsort(array, MAX_SIZE, sizeof(int), compareIntegers);

    printf("sorted array : \n");
    for(int i = 0; i < MAX_SIZE;i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}