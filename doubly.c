#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
int data;
struct Node* next;
struct Node* prev;
}Node;


typedef struct DoublyLinkedList
{
Node* head;
Node* tail;
}
DoublyLinkedList;
Node* createNode(int data)
{
Node* newNode = (Node*) malloc(sizeof(Node));
if (!newNode)
{
printf("Memory error\n");
return NULL;
}
newNode->data = data;
newNode->next = NULL;
newNode->prev = NULL;
return newNode;
}
void initList(DoublyLinkedList* list)
{
list->head = NULL;
list->tail = NULL;
}
void insertAtHead(DoublyLinkedList* list, int data)
{
Node* newNode = createNode(data);
if (list->head == NULL)
{
list->head = list->tail = newNode;
}
else
{
newNode->next = list->head;
list->head->prev = newNode;
list->head = newNode;
}
}
void insertAtTail(DoublyLinkedList* list, int data)
{
Node* newNode = createNode(data);
if (list->tail == NULL)
{
list->head = list->tail = newNode;
} else
{
newNode->prev = list->tail;
list->tail->next = newNode;
list->tail = newNode;
}
}
void deleteFromHead(DoublyLinkedList* list)
{
 if (list->head == NULL)
{
printf("List is empty\n");
}
else if (list->head == list->tail)
{
free(list->head);
list->head = list->tail = NULL;
}
else
{
Node* temp = list->head;
list->head = list->head->next;
list->head->prev = NULL;
free(temp);
}
}
void deleteFromTail(DoublyLinkedList* list)
{
if (list->tail == NULL)
{
printf("List is empty\n");
}
else if (list->head == list->tail)
{
free(list->head);
list->head = list->tail = NULL;
}
else
{
Node* temp = list->tail;
list->tail = list->tail->prev;
list->tail->next = NULL;
free(temp);
}
}
void printList(DoublyLinkedList* list)
{
Node* temp = list->head;
while (temp)
{
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
int main()
{
DoublyLinkedList list;
initList(&list);
int choice,data;
while(1)
{
printf("Doubly Linked List Operations:\n");
printf("1. Insert at Head\n");
printf("2. Insert at Tail\n");
printf("3. Delete from Head\n");
printf("4. Delete from Tail\n");
printf("5. Print List\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
    printf("Enter data to insert at Head: ");
    scanf("%d", &data);
    insertAtHead(&list, data);
    break;
case 2:
    printf("Enter data to insert at Tail: ");
    scanf("%d", &data);
    insertAtTail(&list, data);
    break;
    case 3:
    deleteFromHead(&list);
    break;
case 4:
    deleteFromTail(&list);
    break;
case 5:
    printf("Doubly Linked List: ");
    printList(&list);
    break;
case 6:
    return 0;
    default:
    printf("Invalid choice\n");
}
}
return 0;
}




