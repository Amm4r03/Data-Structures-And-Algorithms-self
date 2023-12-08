// searches for key in linked list using linear search

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    if (head == NULL)
    {
        printf("\n===UNDERFLOW===\n");
        return;
    }
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
    traverse = head;
    int length = 0;
    while(traverse != NULL)
    {
        length +=1;
        traverse = traverse->next;
    }
    return length;
}

void linearSearch(int key)
{
    struct Node* current = head;
    if (listLength() == 0)
    {
        printf("\n====UNDERFLOW====\n");
        return;
    }

    bool keyFound = true;

    for (int i = 0; i < listLength(); i++)
    {
        if(current->data == key)
        {
            printf("key found at node %d", i+1);
            return;
        }
        current = current->next;
    }

    keyFound = false;
    if (!keyFound)
    {
        printf("key not found in linked list");
        return;
    }
}

int main()
{
    head = NULL;

    int entries;
    printf("enter the number of elements to be added in the linked list : ");
    scanf("%d", &entries);

    for(int i = 0; i < entries; i++)
    {
        int entry;
        printf("enter the value for node %d : ", i+1);
        scanf("%d", &entry);
        insertNode(entry);
    }

    printList();

    int searchKey;
    printf("enter key to be found in the linked list : ");
    scanf("%d", &searchKey);

    linearSearch(searchKey);
    
    return 0;
}