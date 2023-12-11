// implementing binary search in array

#include <stdio.h>

int binarySearch(int array[], int key, int start, int end)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (array[mid] == key)
        {
            return mid;
        }
        else
        {
            if(array[mid] > key)
            {
                return binarySearch(array, key, start, mid - 1);
            }
            else
            {
                return binarySearch(array, key, mid + 1, end);
            }
        }
    }
    return -1;
}

int main()
{
    // taking a sorted array
    int numbers[] = {10, 20, 45, 48, 49, 51, 91, 100, 102, 160, 201};

    int size = sizeof(numbers)/sizeof(numbers[0]);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("index : %d",binarySearch(numbers, 49, 0, size));


    return 0;
}