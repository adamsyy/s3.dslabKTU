#include <stdio.h>

#define MAX 100

int stack[MAX], top = -1; // stack array and top

// Push function to insert element
void push(int data)
{
    if (top == MAX - 1)
        printf("\nStack overflow");
    else if (top == -1)
        stack[++top] = data;
    else
    {
        int tempStack[MAX], tempTop = -1;
        while(data > stack[top] && top !=-1)
        {
            int del = stack[top--];
            tempStack[++tempTop] = del;
        }
        stack[++top] = data;
        while(tempTop>=0)
        {
            int del = tempStack[tempTop--];
            stack[++top] = del;
        }
    }
}

// Pop function to pop element
void pop()
{
    int del;
    if (top == -1)
        printf("\nStack empty");
    else
    {
        del = stack[top--];
        printf("\nDeleted: %d", del);
    }
}

// To print elements of stack
void display()
{
    if (top == -1)
        printf("\nStack empty!!\n");
    else
    {
        printf("\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d, ", stack[i]);
        }
        printf(" <-TOP");
    }
}

int main()
{
    int ch, element;
    do
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display stack");
        printf("\n4.Exit");
        printf("\n\nChoose operation: ");
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
        }
    } while (ch < 4);

    return 0;
}