// returns sum of all elements of array

#include <stdio.h>

int arraySum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    printf("%d", arraySum(numbers, size));
    return 0;
}