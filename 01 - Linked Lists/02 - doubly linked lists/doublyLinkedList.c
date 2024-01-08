#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* previous;
    struct Node* next;
};

struct Node* head;
struct Node* tail;

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

void insertNode(int value)
{
    struct Node* newNode = createNode(value);
    newNode->data = value;
    newNode->previous = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->previous = newNode;
    }
    head = newNode;
}

void printList()
{
    struct Node* traverse = head;
    while (traverse != NULL)
    {
        printf("%d ",traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

int listLength()
{
    struct Node* traverse = head;
    int length = 0;
    while (traverse != NULL)
    {
        length++;
        traverse = traverse->next;
    }
    return length;
}

int findLargest()
{
    struct Node* traverse = head;
    int max;
    max = head->data;
    while (traverse != NULL)
    {
        if (traverse->data > max)
        {
            max = traverse->data;
        }
        traverse = traverse->next;
    }
    return max;
}

int findSmallest()
{
    struct Node* traverse = head;
    int min;
    min = head->data;
    while (traverse != NULL)
    {
        if (traverse->data < min)
        {
            min = traverse->data;
        }
        traverse = traverse->next;
    }
    return min;
}

void insertAtPoint(int value, int position)
{
    if (position < 1)
    {
        printf("invalid position : should be an integer value greater than 1\n");
        return;
    }

    struct Node* newNode = createNode(value);
    if (newNode == NULL)
    {
        printf("memory allocation failed\nquitting\n");
        return;
    }

    if (position == 1 || head == NULL)
    {
        insertNode(value);
    }
    else
    {
        struct Node* current = head;
        int currentPos = 1;
        while (currentPos < position - 1 && current->next != NULL)
        {
            current = current->next;
            currentPos++;
        }
        if(currentPos < position - 1)
        {
            printf("position exceeds length of list\nnode will be inserted at the end of the list\n");
        }

        newNode->next = current->next;
        newNode->previous = current;
        if (current->next != NULL)
        {
            current->next->previous = newNode;
        }
        current->next = newNode;
    }
}

int calcSum()
{
    struct Node* traverse = head;
    int sum = 0;
    while (traverse != NULL)
    {
        sum += traverse->data;
        traverse = traverse->next;
    }
    return sum;
}

float calcMean()
{
    return (calcSum()/(float)listLength());
}

int* listToArray()
{
    struct Node* traverse = head;
    
    int* listAsArray = (int*) malloc(listLength() * sizeof(int));
    
    for (int i = 0; traverse != NULL; i++)
    {
        listAsArray[i] = traverse->data;
        traverse = traverse->next;
    }

    return listAsArray;
}

int calcMode()
{
    int* array = listToArray();
    int frequency[listLength()][2];
    int mode;
    for (int i = 0; i < listLength(); i++)
    {
        for (int j = 0; j < listLength() - i; j++)
        {
            // logic for calculating mode
        }
    }
    return mode;
}

int main()
{
    head = NULL;

    int totalNodes;
    printf("enter the number of nodes to be inserted in the list : ");
    scanf("%d", &totalNodes);
    for(int i = 0; i < totalNodes; i++)
    {
        int value;
        printf("enter value for node %d : ", i+1);
        scanf("%d", &value);
        insertNode(value);
    }

    printList();

    int val;
    printf("enter another node : ");
    scanf("%d", &val);
    int pos;
    printf("enter position to place this node : ");
    scanf("%d", &pos);
    insertAtPoint(val, pos);

    printList();

    printf("\n\nlist stats : \n");
    printf("size of a single node : %d bytes\n", sizeof(struct Node));
    printf("length of the list : %d nodes\n", listLength());
    printf("total size occupied : %d bytes\n", listLength() * sizeof(struct Node));
    printf("largest element in list : %d\n", findLargest());
    printf("smallest element in the list : %d\n", findSmallest());
    printf("thus, range of elements : %d\n", findLargest() - findSmallest());
    printf("sum of all elements : %d\n", calcSum());
    printf("mean of elements : %0.2f\n", calcMean());

    int* array = listToArray();
    for(int i = 0; i < listLength(); i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}