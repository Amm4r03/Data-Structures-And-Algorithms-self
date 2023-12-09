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
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
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
    while (traverse != NULL)
    {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

int returnMiddleElement()
{
    int middle;



    return middle;
}

int listLength()
{
    int length;

    struct Node* traverse = head;

    while(traverse != NULL)
    {
        length +=1;
        traverse = traverse->next;
    }

    return length;
}

int main()
{
    head = NULL;
    insertNode(34);
    insertNode(64);
    insertNode(54);
    insertNode(22);

    printList();
    printf("%d", listLength());
    return 0;
}