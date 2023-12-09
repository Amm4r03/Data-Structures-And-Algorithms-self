// reverses an input linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void insertNode(int value)       // inserts value at head
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void printList()
{
    struct Node* traverse = head;

    while(traverse != NULL)
    {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

struct Node* reverseList()
{
    struct Node* currentNode = head;
    struct Node* prevNode = NULL;
    struct Node* nextNode = NULL;

    if (head == NULL)
    {
        printf("===UNDERFLOW===");
        return head;
    }

    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;

        prevNode = currentNode;
        currentNode = nextNode;
    }

    head = prevNode;
    
    return head;
}

int main()
{
    head = NULL;

    // printf("size of a node : %d bytes\nsize of a node pointer : %d", sizeof(struct Node), sizeof(struct Node*));
    insertNode(23);
    insertNode(24);
    insertNode(34);
    insertNode(123);

    printList();

    reverseList();
    printList();

    return 0;
}