
#include <stdio.h>
#include <stdlib.h>
//new function addafterele has been added to implement the functionalty of adding elements after the required node specified by tyhe user

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

void display()
{
    if (first == NULL)
        printf("\nList Empty");
    else
    {
        struct node *temp = first;
        printf("Head");
        while (temp != NULL)
        {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
    }
    printf("\n\n");
}

void delete (int data)
{
    if (first == NULL)
    {
        printf("\nList Empty\n");
    }
    else
    {
        struct node *temp = first, *del = NULL;
        if (first->data == data)
        {
            del = first;
            first = first->next;
            free(del);
            printf("\nElement Deleted! \n");
        }
        else
        {
            while (temp != NULL)
            {
                if (temp->next != NULL && temp->next->data == data)
                {
                    del = temp->next;
                    temp->next = temp->next->next;
                    free(del);
                    printf("\nElement Deleted! \n");
                    break;
                }
                temp = temp->next;
            }
        }
        if (del == NULL)
            printf("\nElement not found! \n");
    }
}
void addbeforeele(int data)
{
    int newdata;
    struct node *temp = first;
    printf("enter value of new node \n");
    scanf("%d", &newdata);
    struct node *newNode = createNode(newdata);
    //incase the head itself is the required node
    if (temp->data == newdata)
    {
        newNode->next=temp;
        first=newdata;
    }
    else    
    {
        while (temp->data != data)
        {
            temp = temp->next;
        }
        newNode->next = temp->next; //to prevent losing of tail after newnode
        temp->next = newNode;
    }
}

int main()
{   //2 4 6 99 8
    //2 4 (99)
    int choice;
    do
    {
        int data;
        printf("1: Add elements\n");
        printf("2: Display Elements\n");
        printf("3: Delete Element\n");
        printf("4: Insert after a node\n");
        printf("5: Exit\n");
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
            display();
            break;
        case 3:
            printf("Enter value that you want to delete: ");
            scanf("%d", &data);
            delete (data);
            break;
        case 4:
        {
            printf("Enter the data of node before which element should be inserted");
            scanf("%d", &data);
            addbeforeele(data);
            break;
        }

        case 5:
            break;
        default:
            printf("Invalid Choice\n");
            break;
        };
    } while (choice != 5);
    return 0;
}