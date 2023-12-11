// insertion of elements in array

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 10;
    int array[size];
    for(int i = 0; i < size; i++)
    {
        printf("enter the value for member %d : ", i+1);
        scanf("%d", &array[i]);
    }

    printf("array recieved is as follows : \n[");
    for(int i = 0; i < size; i++)
    {
        if (i+1==size)
        {
            printf("%d]", array[i]);
        }
        else
        {
            printf("%d, ", array[i]);
        }
    }
    return 0;
}