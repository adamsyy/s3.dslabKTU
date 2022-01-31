
#include <stdio.h>
#include <stdlib.h>
//added search() to search for the element in the linked list
struct node
{
    int data;
    struct node *next;
};
struct node *first = NULL;

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc((sizeof(struct node)));
    if (newNode == NULL)
    {
        printf("Sorry there was an error\n Aborting\n");
        exit(0);
    }
    newNode->next = NULL;
    newNode->data = data;
    return (newNode);
}

void addElemEnd(int data)
{
    struct node *newNode = createNode(data);

    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        struct node *temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void search(int data)
{
    struct node *temp = first;
    int c = 0;
    while (temp != NULL)
    {

        if (temp->data == data) //compares with set of values in list
        {

            printf("yes it is present at position: %d", c);
            return;
        }
        temp = temp->next;
        c++;//maintains a count variable c to keep track of position STARTING FROM ZERO
    }
    printf("\nElement not present");
}

int main()
{
    int choice;
    do
    {
        int data;
        printf("1: Add elements\n");
        printf("2: Search\n");
        printf("4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &data);
            addElemEnd(data);
            break;
        case 2:
        {
            printf("Enter value to search: ");
            scanf("%d", &data);
            search(data);
            break;
        }
        case 4:
            break;
        default:
            printf("Invalid Choice\n");
            break;
        };
    } while (choice != 4);
    return 0;
}