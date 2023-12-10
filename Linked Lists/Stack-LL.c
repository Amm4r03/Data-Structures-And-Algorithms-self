// implementing a stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

// removes element from the stack (returns -1 if stack is empty)
int pop()
{
    if (head == NULL)
    {
        printf("=== UNDERFLOW ===\n");
        return -1;
    }
    else
    {
        struct Node* top = head;
        int value = head->data;
        head = head->next;
        free(top);
        return value;
    }
}

// returns top element of the stack
int top()
{
    if(head == NULL)
    {
        printf("=== UNDERFLOW ===\n");
        return -1;
    }
    else
    {
        int headValue = head->data;
        return headValue;   
    }
}

// 1 : stack is empty; 0 : not empty
int isEmpty()
{
    return (head == NULL) ? 1 : 0;
}

// returns size of stack
int size()
{
    if(head == NULL)
    {
        printf("=== EMPTY STACK ===\n");
        return 0;
    }
    int size = 0;
    struct Node* traverse = head;

    while(traverse != NULL)
    {
        size += 1;
        traverse = traverse -> next;
    }

    return size;
}

// inserts elements into the stack
void push(int value)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// prints the stack
void printStack()
{
    struct Node* traverse = head;

    if (traverse == NULL)
    {
        printf("EMPTY STACK\n");
        return;
    }

    while (traverse != NULL)
    {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;

    printf("Enter the number of elements to be added to the list : ");
    int entries;
    scanf("%d", &entries);

    for (int i = 0; i < entries; i++)
    {
        int value;
        printf("enter the value for node %d : ", i+1);
        scanf("%d", &value);
        push(value);
    }

    printStack();

    printf("using pop() function to remove topmost element, we get : \n");
    printf("value removed : %d\n", pop());
    printf("current stack : ");
    printStack();

    printf("size of the stack : %d items\ntopmost element of stack : %d\nstack empty? : %d", size(), top(), isEmpty());

    return 0;
}