#include<stdio.h>
#include<math.h>
void readpoly(int a[2][100],int size)
{
    int i;
     printf("\nEnter the coeffiecent and power of polynomial, in descending order of power");
    printf("\nFor example: 3X^(5) + 4x^(2) + x + 6 is entered as 3 5 4 2 1 1 6 0\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[0][i]);
        scanf("%d",&a[1][i]);
    }
}

void polydisplay(int a[2][100],int size){
int i;
for(i=0;i<size;i++)
    {
       printf(" %dx^(%d) ", a[0][i], a[1][i]);
        i < size - 1 ? printf("+") : printf(""); 
    }
}

void evalpoly(int a[2][100],int size,int x)
{
    int i,sum=0;
    for(i=0;i<size;i++)
    {
        sum=sum+(a[0][i]*pow(x,a[1][i]));
    }
    printf("\nsum is %d",sum);
}

void main(){
int a[2][100];
int size1;
printf("Enter the size of the polynomial");
scanf("%d",&size1);
    readpoly(a,size1);
    polydisplay(a,size1);
    evalpoly(a,size1,2);
}