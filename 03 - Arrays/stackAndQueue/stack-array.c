// implementation of stack using array

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int* initialiseStack()
{
    int* stack = (int*) malloc(MAX_SIZE * sizeof(int));
    if (stack == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int top = -1;
    return stack;
}

void push(int* stack, int value, int size)
{
    if (sizeof(stack) > MAX_SIZE)
    {
        printf("overflow\n");
    }
    else
    {
        
    }
}

int main()
{
    return 0;
}