// attempts deleting nodes in linked list

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
    newNode->next = head;
    head = newNode;
}

void printList()
{
    struct Node* traverse;
    traverse = head;

    while (traverse != NULL)
    {
        print("%d ", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    return 0;
}