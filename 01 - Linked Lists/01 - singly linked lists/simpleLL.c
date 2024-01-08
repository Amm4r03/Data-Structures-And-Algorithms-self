// code implements a simple linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void insertNode (int value)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = value;

    newNode->next = head;

    head = newNode;
}

void printList()
{
    struct Node* traverse;
    traverse = head;
    
    while (traverse != NULL)
    {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
}

int main()
{
    head = NULL;

    insertNode(25);
    insertNode(35);
    insertNode(55);
    insertNode(16);
    insertNode(74);

    printList();

    return 0;
}