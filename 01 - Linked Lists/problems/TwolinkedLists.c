// writing code to create two linked lists
// testing for merging 2 sorted linked lists

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head1;
struct Node* head2;

void insertNode(struct Node** head, int value)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertMultiple(struct Node** head, int entries)
{
    for(int i = 0; i < entries; i++)
    {
        int value;
        printf("Enter the value for node %d : ", i+1);
        scanf("%d", &value);
        insertNode(head, value);
    }
}

void printList(struct Node** head)
{
    struct Node* traverse = *head;

    while (traverse != NULL)
    {
        printf("%d ",traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

int main()
{
    head1 = NULL;
    head2 = NULL;

    int entries;
    printf("enter number of elements to be inserted in linked lists : ");
    scanf("%d", &entries);

    printf("enter values for linked list 1\n");
    insertMultiple(&head1, entries);

    printf("enter values for linked list 2\n");
    insertMultiple(&head2, entries);

    printf("list 1 : ");
    printList(&head1);

    printf("list 2 : ");
    printList(&head2);

    return 0;
}