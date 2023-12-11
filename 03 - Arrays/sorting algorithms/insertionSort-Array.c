// implementation of insertion sort in array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// trying to populate array using random numbers by making use of time.h library and stdlib
// results in a new array every time the code is run

void insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array [j + 1] = key;
    }
}

int main()
{
    srand(time(NULL));

    int size = 20;
    int numbers[size];

    for (int i = 0; i < size; i++)
    {
        numbers[i] = rand() % 100;      // 100 here is the range
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    insertionSort(numbers, size);

    printf("array after sorting : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}