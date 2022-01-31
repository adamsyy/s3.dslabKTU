
#include <stdio.h>
#include <stdlib.h>

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

void displayy(struct node *head)
{
    if (head == NULL)
        printf("\nList Empty");
    else
    {
        struct node *temp = head;
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

struct node *reverselist()
{

    struct node *prev = NULL;
    struct node *pres = first;
    struct node *nxt = pres->next;
    while (pres != NULL)
    {
        pres->next = prev;
        prev = pres;
        pres = nxt;
        if (nxt != NULL)
        {
            nxt = nxt->next;
        }
    }
    return prev;
}

int main()
{
    int choice;
    do
    {
        int data;
        printf("1: Add elements\n");
        printf("2: Display Elements\n");
        printf("3: reverse list");
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
            display();
            break;
        case 3:
            struct node *rev = reverselist();
            displayy(rev);
            break;
        case 4:
            break;
        default:
            printf("Invalid Choice\n");
            break;
        };
    } while (choice != 4);
    return 0;
}