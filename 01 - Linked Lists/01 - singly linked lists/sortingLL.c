// trying to sort a linked list in C

// code implements a simple linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void swapNodes(struct Node* node1, struct Node* node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

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
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

int listLength()
{
    struct Node* traverse;
    traverse=head;

    int length = 0;

    while (traverse != NULL)
    {
        length += 1;
        traverse = traverse->next;
    }
    
    return length;
}

void sortList(struct Node* head)
{
    if (head == NULL)
    {
        return;
    }

    int length = listLength();

    for(int i = 0; i < length - 1; i++)
    {
        struct Node* currentNode = head;
        struct Node* nextNode = head->next;

        for (int j = 0; j < length - i - 1; j++)
        {
            if(currentNode->data > nextNode->data)
            {
                swapNodes(currentNode, nextNode);
            }
            currentNode = currentNode->next;
            nextNode = nextNode->next;
        }
    }
}

int main()
{
    head = NULL;

    int entries;

    printf("Enter the number of elements to be printed in the linked list : ");
    scanf("%d", &entries);

    for (int i = 0; i < entries; i++)
    {
        int value;
        printf("enter value of node %d : ", i + 1);
        scanf("%d", &value);
        insertNode(value);
    }

    printList();

    printf("current length of list : %d nodes\n", listLength());

    printf("sorted list : \n");
    sortList(head);

    printList();

    return 0;
}