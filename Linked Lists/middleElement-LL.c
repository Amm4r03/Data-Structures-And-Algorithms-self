// returns the middle element of a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

int listLength();

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
    int middle, middleIndex;
    middleIndex = (int)(listLength()/2);
    struct Node* traverse = head;

    int length = 0;

    while (traverse != NULL)
    {
        length += 1;
        if(length == middleIndex)
        {
            break;
        }
        traverse = traverse->next;
    }

    middle = traverse->data;

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

    int entries;

    printf("Enter the number of elements to be added in the linked list : ");
    scanf("%d", &entries);

    for(int i = 0; i < entries; i++)
    {
        int value;
        printf("Enter the value for node %d : ", i+1);
        scanf("%d", &value);
        insertNode(value);
    }

    printList();
    printf("%d\n", listLength());

    printf("middle element of linked list : %d\n", returnMiddleElement());
    return 0;
}