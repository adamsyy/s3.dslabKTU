#include <stdio.h>

#define MAX 100

int stack[MAX]   , top    = -1;  // stack array and top
int auxStack[MAX], auxTop = -1;  // Aux stack keeps track of min value


// Check if Empty
int isEmpty(int top) {
    if(top == -1)
        return 1;
    else
        return 0;
}


// Push function to insert element
void push(int data)
{
    if (top == MAX - 1)
        printf("\nStack overflow");
    else
    {
        // push the given element into the main stack
        stack[++top] = data;

        if(isEmpty(auxTop))
        {
            // if the auxiliary stack is empty, push the given element into it
            auxStack[++auxTop] = data;
        }
        else
        {
            // push the given element into the auxiliary stack
            // if it is less than or equal to the current minimum
            if (data <= auxStack[auxTop] ) {
                auxStack[++auxTop] = data;
            }
        }
    }
}

// Pop function to pop element
void pop()
{
    int del;
    if (top == -1)
    {
        printf("\nStack empty");
    }
    else
    {
        // remove the top element from the main stack
        del = stack[top--];

        // remove the top element from the auxiliary stack only if it is minimum
        if(del == auxStack[auxTop])
        {
            auxTop--;
        }

        printf("\nDeleted: %d", del);
    }
}

// To print elements of stack
void displayStack()
{
    if (top == -1)
        printf("\nStack empty");
    else
    {
        printf("\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d, ", stack[i]);
        }
    }
}


void displayMin()
{
    if(auxTop == -1)
        printf("\nStack Empty");
    else    
        printf("\nMinimum Element : %d", auxStack[auxTop]);
}

int main()
{
    int ch, element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display stack");
        printf("\n4.Display min");
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
            displayStack();
            break;
        case 4:
            displayMin();
            break;
        }
    } while (ch < 5);

    return 0;
}