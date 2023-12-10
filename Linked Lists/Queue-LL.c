// implementation of queue using linked list


// returns the data element available at the front node of the queue without deleting it
int front()
{
    if (head == NULL)
    {
        printf("=== UNDERFLOW ===\n");
        return -1;
    }
    else
    {
        int value;
        struct Node* front = head;
        value = front->data;
        return value;
    }
}

// returns element at rear end without removing it
int rear()
{
    if (head == NULL)
    {
        printf("=== UNDERFLOW ===\n");
        return -1;
    }
    else
    {
        struct Node* traverse = head;
        while (traverse->next != NULL)
        {
            traverse = traverse->next;
        }
        int value = traverse->data;
        return value;
    }
}

// checks if the queue is empty (1 : empty; 0 : not empty)
int isNull()
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// returns size of the queue
int queueSize()
{
    if (head == NULL)
    {
        printf("=== UNDERFLOW ===\n");
        return 0;
    }
    else
    {
        int size = 0;
        struct Node* traverse = head;
        while (traverse != NULL)
        {
            size += 1;
            traverse = traverse->next;
        }
        return size;
    }
}

// prints the entire queue
void printQueue()
{
    if (head == NULL)
    {
        printf("=== UNDERFLOW ===\n");
        return;
    }
    else
    {
        struct Node* traverse = head;
        while(traverse != NULL)
        {
            printf("%d ", traverse->data);
            traverse = traverse->next;
        }
        printf("\n");
    }
}

int main()
{
    head = NULL;

    int entries;

    printf("enter the number of elements to be added in the queue : ");
    scanf("%d", &entries);

    for(int i = 0; i < entries; i++)
    {
        int value;
        printf("Enter the value for node %d : ", i+1);
        scanf("%d", &value);
        enqueue(value);
    }

    printf("current queue : ");
    printQueue();

    printf("value dequeued : %d\n", dequeue());
    printf("queue after dequeue-ing : ");
    printQueue();

    printf("\ncurrent queue stats\ncurrent topmost element of queue : %d\ncurrent rear element of queue : %d\ncurrent size of queue : %d\nisNull? : %d", front(), rear(), queueSize(), isNull());

    return 0;
}