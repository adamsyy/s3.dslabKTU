/*
Read any polynomial of degree n and store in an array. Evaluate this
polynomial for a given value of x.
Eg: 3x^2+2x+1
x=2
evaluation=12+4+1=17  */

#include<stdio.h>
#include<math.h>

struct polynomial{
    int coef;
    int expo;
};

// Function to READ Polynomial
int readpoly(struct polynomial p[]){
    int terms;
    printf("Enter the Total number of terms in the Polynomial : ");
    scanf("%d",&terms);

    printf("\nEnter the Coefficient and Exponents in the DESCENDING order:   \n");
    for (int i = 0; i < terms; i++){
        printf("Enter the Coefficient of Term %d : ",i+1);
        scanf("%d",&p[i].coef);
        printf("Enter the Exponent of Term %d    : ",i+1);
        scanf("%d",&p[i].expo);
    }
    return terms;
}

// Function to DISPLAY the Polynomial
void displaypoly(struct polynomial p[], int t){

    for (int i = 0; i < t; i++){
        printf("%dx^%d ",p[i].coef,p[i].expo);
        if (i<t-1){
            printf("+ ");  
        }   
    }
    printf("\n");
}

// Function to find the result
void resultpoly(struct polynomial p[],int terms,int x){

    int t,sum=0;
    for (int i = 0; i < terms; i++){
        t=(p[i].coef*pow(x,p[i].expo));
        sum=sum+t;
        printf("%d",t);

        if (i<terms-1){
            printf(" + ");
        }
        
    }
    printf(" = %d\n",sum);  
}



int main(){

    struct polynomial p[10];
    int terms=readpoly(p);

    printf("The polynomial is: ");
    displaypoly(p,terms);

    int x;
    printf("Enter the Value of the variable x : ");
    scanf("%d",&x);

    resultpoly(p,terms,x);
    
}