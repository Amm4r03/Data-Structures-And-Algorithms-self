// testing time taken by different sorting algorithms

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void fillRandomValues (int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }
}

int main()
{
    clock_t start, end;

    double bubbleTime, insertionTime, selectionTime;

    srand(time(NULL));

    int size = 100000;

    int numbers[size];

    fillRandomValues(numbers, size);

    start = clock();
    selectionSort(numbers, size);
    end = clock();
    selectionTime = ((double)(end - start))/ CLOCKS_PER_SEC;

    fillRandomValues(numbers, size);
    start = clock();
    insertionSort(numbers, size);
    end = clock();
    insertionTime = ((double)(end - start))/CLOCKS_PER_SEC;

    fillRandomValues(numbers, size);
    start = clock();
    bubbleSort(numbers, size);
    end = clock();
    bubbleTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("time taken by different algorithms to sort array\nbubble sort : %f seconds\ninsertion sort : %f seconds\nselection sort : %f seconds\n", bubbleTime, insertionTime, selectionTime);


    return 0;
}