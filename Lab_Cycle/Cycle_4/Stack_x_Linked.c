#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int val)
{

    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;

    //make the new node points to the head node
    newNode->next = head;

    //make the new node as head node
    head = newNode;
}

void pop()
{
    struct node *temp = head;

    if (head == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Poped element = %d\n", head->data);

        //make the head node points to the next node after printing it
        head = head->next;
    }
}

void printList()
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice;
    do
    {
        int data;

        printf("1: Add elements\n");
        printf("2: pop Elements\n");
        printf("3: display Element\n");
        printf("4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter element to insert");

            scanf("%d", data);
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            printList();
            break;
        case 4:
            break;

        default:
            break;
        }
    } while (choice != 4);
    return 0;
}