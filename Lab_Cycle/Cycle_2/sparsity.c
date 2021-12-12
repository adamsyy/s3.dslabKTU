#include<stdio.h>
struct matrix{
    int row;
    int column;
    int value;
};
int main(){
    int n,i,j,m,a[20][20];
    struct matrix k[300];
    printf("Enter the matrix:\n ");
    printf("Enter the number of rows: \n");
    scanf("%d",&n);
    printf("Enter the number of columns:\n");
    scanf("%d",&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Enter the element: ");
            scanf("%d",&a[i][j]);
        }
    }
    k[0].row=n;
    k[0].column=m;
    int c=1;
    int ctr=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]!=0){
                k[c].row=i;
                k[c].column=j;
                k[c].value=a[i][j];
                c++;
                ctr++;
            }
        }
    }
    int numofzero=0;
    for(i=0;i<n;i++){
        for(j-0;j<m;j++){
            if(a[i][j]==0){
                numofzero++;
            }
        }
    }
    k[0].value=ctr;
    printf("The new storage mechanism: \n");
    for(i=0;i<=ctr;i++){
        printf("Row: %d        Column: %d     Value: %d    \n",k[i].row,k[i].column,k[i].value);
    }
   
    
    
}