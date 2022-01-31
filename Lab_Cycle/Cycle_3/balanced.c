#include <stdio.h>

#define MAX 100

char stack[MAX], top = -1; // stack array and top

// Push function to insert element
void push(char data)
{
    if (top == MAX - 1)
        printf("\nStack overflow");
    else
        stack[++top] = data;
}

// Pop function to pop element
char pop()
{
    char del;
    if (top == -1)
    {
        printf("\nStack empty");
        return '\0';
    }
    else
    {
        del = stack[top--];
        return del;
    }
}



// To print elements of stack
// debug
void display()
{
    if (top == -1)
        printf("\nStack empty");
    else
    {
        printf("\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%c, ", stack[i]);
        }
    }
}

int isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

int isOpeningBracket(char ch)
{
    if(ch == '(' || ch == '{' || ch == '[')
        return 1;
    else
        return 0;
}

int isClosingBracket(char ch)
{
    if(ch == ')' || ch == '}' || ch == ']')
        return 1;
    else
        return 0;
}

int areBracketsBalanced(char exp[])
{
    int i = 0;
    while(exp[i] !='\0')
    {
        if(isOpeningBracket( exp[i]) )
        {
            push(exp[i]);
        }
        else if(isClosingBracket(exp[i]))
        {
            // if stack is empty, ie no opening bracket
            // but we get closing bracket, then invalid
            // eg : ()}
            if(top == -1)
            {
                return 0;
            }
            else 
            {
                // if pair is macthing, valid else invalid
                if( isMatchingPair( pop(),exp[i] ) ) 
                {
                    // do nothing
                }
                else
                {
                    return 0;
                }
            }
        }
        i++;
    }
    // if stack is empty on reaching expression end
    if(top == -1)
        return 1;
    // eg of stack not empty but exp end
    // {()
    else
        return 0;
}

int main()
{
    char exp[MAX];
    printf("Enter an Expression: ");
    scanf("%s",exp);
    int flag = areBracketsBalanced(exp);
    if(flag)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}