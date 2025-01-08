
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}
Node;


typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

Node* createNode(int data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
}
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initQueue(Queue* q)
{
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q)
{
    return (q->front == NULL);
}

void enqueue(Queue* q, int data)
{
    Node* newNode = createNode(data);
    if (isEmpty(q))
{
        q->front = q->rear = newNode;
} else
{
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Element %d added to queue\n", data);
}

int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    printf("Element %d removed from queue\n", data);
    return data;
}

void printQueue(Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Queue q;
    initQueue(&q);
    int choice, data;
    while (1) {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
