#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int coeff;
int exp;
struct node* next;
} node;

void get_data(node* head)
{
int ch;
do {
printf("\nEnter the coeff : ");
scanf("%d",&(head->coeff));
printf("\nEnter the exponent : ");
scanf("%d",&(head->exp));
head->next = NULL;
printf("\nWant to enter more data? (0/1) :");
scanf("%d",&ch);
if(ch) {
head->next = (node*)malloc(sizeof(node));
head = head->next;
head->next = NULL;
}
} while(ch);
}

void display(node* head)
{
while(head->next != NULL)
{
printf("(%d.x^%d)+",head->coeff,head->exp);
head = head->next;
}
printf("(%d.x^%d)\n",head->coeff, head->exp);
}

node* add(node* result, node* poly1, node* poly2)
{
node* temp,*temp1;
temp = result;
while(poly1 && poly2)
{
if(poly1->exp > poly2->exp)
{
result->exp = poly1->exp;
result->coeff = poly1->coeff;
poly1=poly1->next;
}
else if(poly1->exp < poly2->exp)
{
result->exp = poly2->exp;
result->coeff = poly2->coeff;
poly2=poly2->next;
}
else
{
result->exp = poly1->exp;
result->coeff = poly1->coeff + poly2->coeff;
poly1 = poly1->next;
poly2 = poly2->next;
}
if(poly1 || poly2)
{
result->next = (node*)malloc(sizeof(node));
result = result->next;
result->next = NULL;
}
}

while(poly1 || poly2)
{

if(poly1)
{
result->coeff = poly1->coeff;
result->exp = poly1->exp;
poly1 = poly1->next;
}

if(poly2)
{
result->coeff = poly2->coeff;
result->exp = poly2->exp;
poly2 = poly2->next;
}
if(~(poly1 || poly2))
{
break;
}
result->next = (node*)malloc(sizeof(node));
result = result->next;
result->next = NULL;
}
while(result)
{
temp1 = result;
result = result->next;
free(temp1);
}
return temp;
}

node* multiply(node* result, node* poly1, node* poly2)
{
node* ptr,*new,*result1;
node* temp = poly2;
node* temp1 = (node*)malloc(sizeof(node));
ptr = (node*)malloc(sizeof(node));
new = ptr ;
result1 = result;
ptr->next = NULL;
while(poly1 != NULL)
{
while(poly2 != NULL)
{
ptr->coeff = (poly1->coeff) * (poly2->coeff);
ptr->exp = poly1->exp + poly2->exp;
poly2 = poly2->next;

if(poly2)
{
ptr->next = (node*)malloc(sizeof(node));
ptr = ptr->next;
ptr->next = NULL;
}
}
poly2 = temp;

result = add(temp1,new,result1);

result1 = temp1;

poly1 = poly1->next;
ptr = new;
}
while(ptr)
{
new=ptr;
ptr=ptr->next;
free(new);
}
return(result);

}

int main()
{
node* poly1 = (node*)malloc(sizeof(node));
node* result = (node*)malloc(sizeof(node));
node* poly2 = (node*)malloc(sizeof(node));
node* temp;
result->next = NULL;
result->coeff = 0;
result->exp = 0;

get_data(poly1);
display(poly1);
get_data(poly2);
display(poly2);

//printf("\nThe sum is : ");
//add(result,poly1,poly2);
//display(result);

printf("\nThe product is : ");
result = multiply(result, poly1, poly2);
display(result);

while(result)
{
temp = result;
result = result->next;
free(temp);
}
while(poly1)
{
temp = poly1;
poly1 = poly1->next;
free(temp);
}
while(poly2)
{
temp = poly2;
poly2 = poly2->next;
free(temp);
}
return 0;
}
