// returns the middle element of a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void insertNode(int value)      //  inserts nodes at the end of the linked list
{
    struct Node* newNode;
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node* temp;
        temp = head;
        while (temp->next != NULL)
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
    while (traverse != head)
    {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    return 0;
}