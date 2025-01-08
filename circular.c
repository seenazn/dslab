#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int isEmpty()
{
return (front == -1);
}
int isFull()
{
return ((rear + 1) % MAX_SIZE == front);
}
void enqueue(int data)
{
if (isFull())
{
printf("Queue is full.\n");
return;
}
if (isEmpty())
{
front = rear = 0;
}
else
{
rear = (rear + 1) % MAX_SIZE;
}
queue[rear] = data;
printf("Element %d added to queue.\n", data);
}
int dequeue()
{
if (isEmpty())
{
printf("Queue is empty.\n");
return -1;
}
int data = queue[front];
if (front == rear)
{
front = rear = -1;
}
else
{
front = (front + 1) % MAX_SIZE;
}
printf("Element %d removed from queue.\n", data);
return data;
}
void printQueue()
{
if (isEmpty())
{
printf("Queue is empty.\n");
return;
}
int temp = front;
printf("Queue elements: ");
do
{
printf("%d ", queue[temp]);
temp = (temp + 1) % MAX_SIZE;
}
while (temp != (rear + 1) % MAX_SIZE);
printf("\n");
}
int main()
{
int choice, data;
while (1)
{
printf("Circular Queue Operations:\n");
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
enqueue(data);
break;
case 2:
dequeue();
break;
case 3:
printQueue();
break;
case 4:
return 0;
default:
printf("Invalid choice.\n");
}
}
return 0;
}
