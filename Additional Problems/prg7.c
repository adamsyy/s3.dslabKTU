/*
Given a sparse matrix. Represent and store it using an efficient
method. Also find the sparsity (The sparsity of a matrix can be
quantified with a score, which is the number of zero values in the
matrix divided by the total number of elements in the matrix.)
*/

#include <stdio.h>

void displaymatrix(int arr[][10],int m,int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
}

// Main Function
int main(){

    // Reading and Printing the Matrix
    int r,c,a[10][10];
    printf("Enter the Number of ROWS: ");
    scanf("%d",&r);
    printf("Enter the Number of COLUMNS: ");
    scanf("%d",&c);

    printf("Enter the Matrix Elements: \n");

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("Enter Element A%d%d : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("The Matrix is: \n");
    displaymatrix(a,r,c);


    // Finding sparse Matrix
    int sparse[20][3];

    int k=0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            
            if (a[i][j]!=0){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][3]=a[i][j];
                k++;
            }  
        }  
    }

    printf("The SPARSE Matrix is: \n");
    for (int i = 0; i < k; i++){
        for (int j = 0; j < 3; j++){
            printf("%d  ",sparse[i][j]);
        }
        printf("\n");
    }
}