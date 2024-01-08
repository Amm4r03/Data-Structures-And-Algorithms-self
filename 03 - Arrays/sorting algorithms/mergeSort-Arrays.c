#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void merge(int array[], int start, int mid, int end)
{
    int temp[MAX_SIZE];
    int i = start, j = mid + 1, k = end;
    if (i <= mid && j <= end)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++, k++;
        }
        else
        {
            temp[k] = array[j];
            j++, k++;
        }
        while (i <= mid)
        {
            temp[k] = array[i];
            i++, k++;
        }
        while(j <= end)
        {
            temp[k] = array[j];
            j++, k++;
        }
        for(int p = start; p <= end; p++)
        {
            array[p] = temp[p];
        }
    }
}

void mergeSort(int array[], int low, int high)
{
    int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
    return;
}

int main()
{
    srand(time(NULL));

    // initialising array with random values
    int array[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++)
    {
        array[i] = rand() % 100;
    }

    printf("current array : \n");
    for(int i = 0; i < MAX_SIZE;i++)
    {
        printf("%d ", array[i]);
    }

    // sorting algorithm
    mergeSort(array, 0, MAX_SIZE - 1);
    
    // printing sorted array
    printf("sorted array : \n");
    for(int i = 0; i < MAX_SIZE;i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}