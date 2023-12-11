// implementing linear search in arrays

#include <stdio.h>

void linearSearch(int array[], int size, int key)
{
    int keyFound = 0;
    for(int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            keyFound = 1;
            printf("found key (%d) at index %d\n", key, i);
            break;
        }
    }
    if (!keyFound)
    {
        printf("key not found in the array\n");
    }
}

int main()
{
    int numbers[] = {23, 34, 56, 32, 33, 56, 36, 78, 12, 78, 91};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int key;
    printf("enter value to be searched in the given array : ");
    scanf("%d", &key);

    linearSearch(numbers, size, key);

    return 0;
}