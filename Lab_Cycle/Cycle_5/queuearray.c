#include <stdio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Push function to insert element
void push(int data)
{
    if (rear == MAX - 1)
        printf("\n Queue overflow");
    else if(rear == -1)
    {
    	front = 0;
    	rear  = 0;
    	queue[rear] = data;
    }
    else
		queue[++rear] = data;
}

// Pop function to pop element
void pop()
{
    int del;
    if (front == -1)
        printf("\nQueue empty");
    else if(front == rear)
    {
    	printf("\nDeleted: %d", queue[front]);
    	front = -1;
    	rear  = -1;
    }
    else
    {
        del = queue[front++];
        printf("\nDeleted: %d", del);
    }
}


// Displays front element without popping it
int peek()
{
	if(front == -1)
		return -1;
	else
		return queue[front];
}


// To print elements of queue
void display()
{
    if (front== -1)
        printf("\nQueue empty");
    else
    {
        printf("\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d, ", queue[i]);
        }
    }
}

int main()
{
    int ch, element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display queue");
        printf("\n4.Display Front Element");
        printf("\n5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
	        if(front == -1)
	        {
	        	printf("Queue Empty!");
	        }
	        else
	        {
                printf("Front element: %d", peek());
	        }
            break;
        }
    } while (ch < 5);

    return 0;
}