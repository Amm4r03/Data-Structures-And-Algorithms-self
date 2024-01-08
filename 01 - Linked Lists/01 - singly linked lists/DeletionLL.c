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
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

void deleteNode(struct Node** head, int key)
{
    int temp;
    if (head == NULL)
    {
        print("\n===EMPTY LINKED LIST===\n");
        return;
    }

    else
    {
        if ((*head)->data == key)
        {
            struct Node* temp = *head;
            *head = (*head)->next;
            free(temp);
            return;
        }
    }
}

int main()
{
    head = NULL;
    return 0;
}