#include<stdio.h>
#include<stdlib.h>
#define NULL 0

void main()
{ 

struct poly
{
int coff;
int expo;
struct poly *link;
}*temp1,*start1,*temp2,*start2,*start3,*temp3;

int n,i,z=1,num;
char c; 

clrscr();

start1=NULL;
printf("\tPolynomial Creation\n\n");
while(1)

{
if(start1==NULL)
{

 


temp1=(struct poly*)malloc(sizeof(struct poly));
printf("Enter Coefficient and Exponent for Node %d\n",z);

scanf("%d %d",&temp1->coff,&temp1->expo);

start1=temp1;
temp1->link=NULL;

}
else
{

temp1->link=(struct poly*)malloc(sizeof(struct poly));
temp1=temp1->link;
printf("Enter Coefficient and exponent for Node %d\n",z);
scanf("%d %d",&temp1->coff,&temp1->expo);

}

z++;
printf("Do you want to create another node\n");
fflush(stdin);
 
scanf("%c",&c);
 
if(c!='y')

{
temp1->link=NULL;
break;
}
}

start2=NULL;
temp2=NULL;
z=1;
while(1)
{
 
if(start2==NULL)
{ 
temp2=(struct poly*)malloc(sizeof(struct poly));
printf("Enter Coefficient and exponent for Node %d\n",z);
scanf("%d %d",&temp2->coff,&temp2->expo);
start2=temp2;
temp2->link=NULL;
}
else
{

temp2->link=(struct poly*)malloc(sizeof(struct poly));
temp2=temp2->link;
printf("Enter Coefficient and exponent for Node %d\n",z);
scanf("%d %d",&temp2->coff,&temp2->expo);

}

z++; 
printf("Do you want to create another node\n");
fflush(stdin);
scanf("%c",&c);

if(c!='y')
{
temp2->link=NULL;
break;
}

}

//Traversing
temp1=NULL;
temp2=NULL;
temp1=start1;
temp2=start2;

 


printf("Traversal of Polynomial Linked List 1\n");

while(temp1!=NULL)

{

printf("%2dx^%d-",temp1->coff,temp1->expo);
temp1=temp1->link;

}

printf("\b \b");
printf("\nTraversal of Polynomial Linked List 2\n");

while(temp2!=NULL)

{

printf("%2dx^%d -",temp2->coff,temp2->expo);
temp2=temp2->link;

}

printf("\b \b");

// subtraction
temp1=NULL;
temp2=NULL;
temp1=start1;
temp2=start2;
temp3=NULL;
start3=NULL;

while(1)

{

if((temp1!=NULL)||(temp2!=NULL))

{

if(start3==NULL)

{

if((temp1->expo)==(temp2->expo))

{

temp3=(struct poly*)malloc(sizeof(struct poly));
temp3->coff= (temp1->coff) - (temp2->coff);
temp3->expo=temp1->expo;
start3=temp3;
temp1=temp1->link;
temp2=temp2->link;
temp3->link=NULL;

}

else if(temp1->expo>temp2->expo)

{

temp3=(struct poly*)malloc(sizeof(struct poly));
temp3->coff=temp1->coff;
temp3->expo=temp1->expo;
start3=temp3;
temp1=temp1->link;
temp3->link=NULL;

}

else

{

temp3=(struct poly*)malloc(sizeof(struct poly));
temp3->coff=temp2->coff;
temp3->expo=temp2->expo;
start3=temp3;
temp2=temp2->link;
temp3->link=NULL;

}

}

else

{

if(temp1->expo==temp2->expo)

{

temp3->link=(struct poly*)malloc(sizeof(struct poly));
temp3=temp3->link;
temp3->coff= (temp1->coff) - (temp2->coff);
temp3->expo=temp1->expo;
temp1=temp1->link;
temp2=temp2->link;

}

else if(temp1->expo>temp2->expo)

{

temp3->link=(struct poly*)malloc(sizeof(struct poly));
temp3=temp3->link;
temp3->coff=temp1->coff;
temp3->expo=temp1->expo;
temp1=temp1->link;

}

else

{

temp3->link=(struct poly*)malloc(sizeof(struct poly));
temp3=temp3->link;
temp3->coff=temp2->coff;
temp3->expo=temp2->expo;
temp2=temp2->link;

}

}

}

else

break;

}

temp3->link=NULL;

//traversing temp3
temp3=NULL;
temp3=start3;
printf("\nTraversal of Polynomial Linked List after subtracting Temp1 & Temp2\n");

while(temp3!=NULL)

{

printf("%2dx^%d - ",temp3->coff,temp3->expo);
temp3=temp3->link;

}

printf("\b\b");
printf("\n the end\n");


}
