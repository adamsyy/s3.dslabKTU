#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node *rear = NULL;

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
		rear  = newNode;
		rear->next = rear;
    }
    else
    {
		newNode->next = rear->next;
		rear->next = newNode;
		rear = newNode;
    }
    printf("Pushed: %d\n", rear->data);
}

void peek()
{
    if(rear == NULL)
        printf("\n Queue Empty");
    else
    {
        printf("\n Front: %d", rear->next->data);
    }
    printf("\n");
}

void pop()
{
    if(rear == NULL)
    {
        printf("\n Queue Empty\n");
    }
    else
    {
    	printf("Popped: %d\n", rear->next->data);
    	struct node* temp = rear->next;
    	if(rear == rear->next)
    		rear = NULL;
		else
		{
			rear->next = rear->next->next;
		}
		free(temp);	
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