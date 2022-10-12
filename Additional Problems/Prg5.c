/*Write a program to read two polynomials and store them in an array.
Calculate the sum of the two polynomials and display the first
polynomial, second polynomial and the resultant polynomial.*/




#include <stdio.h>


struct polynomial{

    int coef;
    int expo;
};

struct polynomial p1[10],p2[10],p3[10];

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

int addpoly(struct polynomial p1[],struct polynomial p2[],int t1, int t2, struct polynomial p3[]){

    int i=0,j=0,k=0;
    while (i<t1 && j<t2){
        if (p1[i].expo==p2[j].expo){
            
            p3[k].coef=p1[i].coef+p2[j].coef;
            p3[k].expo=p1[i].expo;

            i++;
            j++;
            k++;
        }
        else if(p1[i].expo>p2[j].expo){

            p3[k].coef=p1[i].coef;
            p3[k].expo=p1[i].expo;
            i++;
            k++;
        }
        else if(p1[i].expo<p2[j].expo){

            p3[k].coef=p2[j].coef;
            p3[k].expo=p2[j].expo;
            j++;
            k++;
        }
    }

    //for remaining terms in p1[]
    while (i<t1){
        p3[k].coef=p1[i].coef;
        p3[k].expo=p1[i].expo;
        i++;
        k++;
    }

    //for remaining terms in p2[]
    while (j<t2){
        p3[k].coef=p2[j].coef;
        p3[k].expo=p2[j].expo;
        i++;
        k++;
    }
    return k;  
}

int displaypoly(struct polynomial p[], int t){

    for (int i = 0; i < t; i++){
        printf("%dx^%d ",p[i].coef,p[i].expo);
        if (i<t-1){
            printf("+ ");  
        }   
    }
    printf("\n");
}

// MAIN FUNCTION
int main(){

    // Polynomial 1
    printf("\nPolynomial 1 : \n");
    int t1=readpoly(p1);

    printf("Polynomial 1: ");
    displaypoly(p1,t1);

    // Polynomial 2
    printf("\nPolynomial 2: \n");
    int t2=readpoly(p2);

    printf("Polynomial 2: ");
    displaypoly(p2,t2);

    // Adding Polynomial

    int t3=addpoly(p1,p2,t1,t2,p3);

    printf("\n Resultant Polynomial: ");
    displaypoly(p3,t3);

    return 0;
}