#include <stdio.h>
#include <conio.h>
 
#define MAX 5
 
void enqueue();
void dequeue();
void display();
int queue_array[MAX];
int rear = - 1;
int front = - 1;
main()
{
    int choice;
    while (1)
    {
    printf("\n1.Insert element to queue");
    printf("\n2.Delete element from queue");
    printf("\n3.Display all elements of queue");
    printf("\n4.Quit\n");
    printf("\nEnter your choice : ");
    scanf("\n%d", &choice);
    switch (choice)
    {
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(1);
        default:
        printf("Wrong choice \n");
    } /* End of switch */
    } /* End of while */
} /* End of main() */

void enqueue()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
    if (front == - 1)
    /*If queue is initially empty */
    {
    front = 0;
    }
    printf("\nInset the element in queue : ");
    scanf("\n%d", &add_item);
    rear = rear + 1;
    queue_array[rear] = add_item;
    }
} /* End of insert() */

void dequeue()
{
    if (front == - 1)
    {
    printf("Queue Underflow \n");
    return ;
    }
    else
    {
    printf("Element deleted from queue is : %d\n", queue_array[front]);
    front = front + 1;
    if (front > rear)
    {
        front=rear=-1;
    }
    }
} /* End of delete() */

void display()
{
    int i;
    if (front == - 1)
    printf("Queue is empty \n");
    else
    {
    printf("Queue is \n");
    for (i = front; i <= rear; i++)
        printf("%d ", queue_array[i]);
    printf("\n");
    }
} /* End of display() */