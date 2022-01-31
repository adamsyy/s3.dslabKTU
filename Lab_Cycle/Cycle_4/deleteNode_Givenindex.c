
#include <stdio.h>
#include <stdlib.h>
//function delete has been added to remove node at a particular index as per users choice

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

void delete (int index)
{
    if (first == NULL)
    {
        printf("\nList Empty\n");
    }
    else
    {
        struct node *temp = first, *del = NULL;
      for(int i=1;i<index;i++){
          temp=temp->next;//go till we get thatindex
      }
      temp->next=temp->next->next;//skip that node over to next one when we get the one/
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
            printf("Enter index of node you want to delete: ");
            scanf("%d", &data);
            delete(data);
            break;
        case 4:
        {
            break;
        }
        default:
            printf("Invalid Choice\n");
            break;
        };
    } while (choice != 4);
    return 0;
}