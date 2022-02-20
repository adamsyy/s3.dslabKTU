#include <stdio.h>

#define MAX 5

int queue[MAX], front = -1, rear = -1;

int isEmpty()
{
	return(front == -1);
}

// Push function to insert element
void push(int data)
{
    if( (front == 0 && rear == MAX - 1) ||
    	(rear == front-1)
		)
        printf("\n Queue overflow");
    else if(front == -1)
    {
    	front = 0;
    	rear  = 0;
    	queue[rear] = data;
    }
    else
    {
    	rear = ++rear%MAX;
	queue[rear] = data;
    }
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
    	del = queue[front];
        printf("\nDeleted: %d", del);
        front = ++front%MAX;
    }
}


// Displays front element without popping it
int peek()
{
	if(front == -1)
		printf("\nQueue empty");
	else
		printf("\n Front: %d", queue[front]);
}


// To print elements of queue
void display()
{
    if (front== -1)
        printf("\nQueue empty");
    else if(front <= rear)
    {
        printf("\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d, ", queue[i]);
        }
    }
    else
    {
    	for(int i=front; i<MAX; i++)
    		 printf("%d, ", queue[i]);
		for(int i=0; i<=rear; i++)
    		 printf("%d, ", queue[i]);
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
			peek();
            break;
        }
    } while (ch < 5);

    return 0;
}