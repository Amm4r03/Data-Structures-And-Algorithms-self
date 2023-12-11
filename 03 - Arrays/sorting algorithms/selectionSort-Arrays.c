// implementing selection sort in array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        int j = i + 1;
        for (j; j < size; j++)
        {
            if(array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }

        int temp;
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

int main()
{
    srand(time(NULL));

    int size = 30;

    int numbers[size];

    for(int i = 0; i < size; i++)
    {
        numbers[i] = rand() % 100;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    selectionSort(numbers, size);

    printf("array after sorting : \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}