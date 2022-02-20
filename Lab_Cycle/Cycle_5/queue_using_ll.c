#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node *front = NULL, *rear = NULL;

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc((sizeof(struct node)));
    if(newNode == NULL)
    {
        printf("Sorry there was an error\n Aborting\n");
        exit(0);
    }
    newNode->next = NULL;
    newNode->data = data;
    return(newNode);
}

void push(int data)
{
    struct node *newNode = createNode(data);
    if(rear == NULL)
    {
		front = newNode;
		rear  = newNode;
    }
    else
    {
		rear->next = newNode;
		rear = newNode;
    }
    printf("Pushed: %d\n", data);
}

void peek()
{
    if(front == NULL)
        printf("\n Queue Empty");
    else
    {
        printf("\n Front: %d", front->data);
    }
    printf("\n");
}

void pop()
{
    if(front == NULL)
    {
        printf("\n Queue Empty\n");
    }
    else
    {
    	printf("Popped: %d\n", front->data);
    	struct node* temp = front;
    	front = front->next;
    	free(temp);
    	if(front == NULL)
    		rear = NULL;
    }
}

int main()
{
    int choice;
    do
    {
        int data;
        printf("1: Push\n");
        printf("2: Peek\n");
        printf("3: Pop\n");
        printf("4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                peek();
                break;
            case 3:
                pop();
                break;
            case 4:
                break;
            default:
                printf("Invalid Choice\n");
                break;
        };
    }while(choice != 4);
    return 0;
}