// Find the intersection of two sets

#include<stdio.h>

int main(){

    // Details of Set1
    int n,set1[100];
    printf("Enter the total number of elements in Set1: ");
    scanf("%d",&n);

    printf("Enter the Elements \n");
    for (int i=0;i<n;i++){
        scanf("%d",&set1[i]);
    }
    
    printf("\n");

    //Details of Set2
    int m,set2[100];
    printf("Enter the total number of elements in Set2: ");
    scanf("%d",&m);

    printf("Enter the Elements \n");
    for (int i=0;i<m;i++){
        scanf("%d",&set2[i]);
    } 

    int i,j;
    printf("The intersection is: ");
    for (i=0;i<n;i++){
        
        for (j=0;j<m;j++){
            
            if (set1[i]==set2[j]){
                printf("%d ",set1[i]);
            }    
        }
    }
}