// C implementation of the approach
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stack;
int top = -1;

// push function
void push(char ele)
{
	stack[++top] = ele;
}

// pop function
char pop()
{
	return stack[top--];
}

// Function that returns 1
// if str is a palindrome
int isPalindrome(char str[])
{
	int length = strlen(str);

	// Allocating the memory for the stack
	stack = (char*)malloc(length * sizeof(char));

	// Finding the mid
	int i, mid = length / 2;

	for (i = 0; i < mid; i++) {
		push(str[i]);
	}

	// Checking if the length of the string
	// is odd, if odd then neglect the
	// middle character
	if (length % 2 != 0) {
		i++;
	}

	// While not the end of the string
	while (str[i] != '\0') {
		char ele = pop();

		// If the characters differ then the
		// given string is not a palindrome
		if (ele != str[i])
			return 0;
		i++;
	}

	return 1;
}

// Driver code
int main()
{
	char str[100];
    printf("Enter a string: ");
    scanf("%s",str);

	if (isPalindrome(str)) {
		printf("This is a palindrome\n");
	}
	else {
		printf("This is not a palindrome\n");
	}

	return 0;
}