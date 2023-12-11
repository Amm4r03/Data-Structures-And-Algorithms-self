// reverses an input array in-place

#include <stdio.h>

void reverseArray(int arr[], int size)
{
    for (int i = 0; i < (int)(size/2); i++)
    {
        int temp;
        // swap values for arr[i] and arr[size-i-1]
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main()
{
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    reverseArray(numbers, size);

    printf("reversed array :\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ",numbers[i]);
    }
    printf("\n");

    return 0;
}