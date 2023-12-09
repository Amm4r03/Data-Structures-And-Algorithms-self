// deletes a node from the linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void insertNode(int value)      // inserts node at the end of the linked list
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
        struct Node* traverse = head;

        while(traverse->next != NULL)
        {
            traverse = traverse->next;
        }
        traverse -> next = newNode;
    }
}

void printList()
{
    struct Node* traverse = head;
    while (traverse != NULL)
    {
        printf("%d  ",traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

void deleteNodeByValue(int key)      // key = value to be searched, removeAll = true (removes all instances), false(removes only first instance)
{
    struct Node* currentNode = head;
    struct Node* previousNode = NULL;

    if (head == NULL)
    {
        printf("===EMPTY LINKED LIST===");
        return;
    }
    bool keyFound = false;
    // implementing linear search to find element to be removed

    while (currentNode != NULL)
    {
        keyFound = false;
        if (currentNode->data == key)
        {
            keyFound = true;
            if (currentNode == head)
            {
                head = currentNode->next;
            }
            else
            {
                previousNode->next = currentNode->next;
            }
            free(currentNode);  
        }
        else
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    if (!keyFound)
    {
        printf("key not found in the linked list\n");
    }
}

int main()
{
    head = NULL;

    int entries;

    printf("Enter the number of nodes to be added in the linked list : ");
    scanf("%d", &entries);

    for (int i = 0; i < entries; i++)
    {
        int value;
        printf("enter the value for node %d : ", i + 1);
        scanf("%d", &value);
        insertNode(value);
    }

    printf("current list is as follows :\n");
    printList();

    int key;

    printf("enter the value to be removed from the linked list : ");
    scanf("%d", &key);

    deleteNodeByValue(key);

    printf("the list now obtained is as follows : \n");
    printList();

    return 0;
}