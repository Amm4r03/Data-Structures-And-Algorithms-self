// implementing bubble sort

#include <stdio.h>

void bubbleSort(int array[], int size)
{
    int temp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{   
    int numbers[] = {23, 31, 11, 1, 2, 11, 56, 87, 101, 23, 52, 10, 19};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    
    for(int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    bubbleSort(numbers, size);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}