// inserts new nodes at the end of the linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void insertNode(int value)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList()
{
    struct Node* traverse;
    traverse = head;
    while(traverse != NULL)
    {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;

    int entries;

    printf("enter the number of elements to be printed in the linked list : ");
    scanf("%d", &entries);

    for(int i = 0; i < entries; i++)
    {
        int value;
        printf("Enter the value for node %d : ", i+1);
        scanf("%d", &value);
        insertNode(value);
    }

    printList();

    return 0;
}