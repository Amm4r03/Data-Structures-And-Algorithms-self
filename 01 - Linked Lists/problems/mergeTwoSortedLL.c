// writing code to create two linked lists
// testing for merging 2 sorted linked lists

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head1;     // input list
struct Node* head2;     // input list
struct Node* head3;     // merged linked list

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

void mergeSorted(struct Node** list1, struct Node** list2)
{
    struct Node* traverseList1 = *list1;
    struct Node* traverseList2 = *list2;

    while (traverseList1 != NULL && traverseList2 != NULL)
    {
        if (traverseList1->data <= traverseList2->data)
        {
            insertNode(&head3, traverseList1->data);
            traverseList1 = traverseList1->next;
        }
        else
        {
            insertNode(&head3, traverseList2->data);
            traverseList2 = traverseList2->next;
        }
    }
    while (traverseList1 != NULL)
    {
        insertNode(&head3, traverseList1->data);
        traverseList1 = traverseList1->next;
    }

    while (traverseList2 != NULL)
    {
        insertNode(&head3, traverseList2->data);
        traverseList2 = traverseList2->next;
    }
}

int main()
{
    head1 = NULL;
    head2 = NULL;
    head3 = NULL;

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

    mergeSorted(&head1, &head2);

    printf("merged list : ");
    printList(&head3);

    return 0;
}