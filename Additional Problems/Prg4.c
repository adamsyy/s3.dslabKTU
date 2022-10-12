// Program 5: Binary to hexadecimal


#include<stdio.h>
#include<math.h>

int main(){

    int n,a[10][10];
    printf("Enter the NUmber of Rows: ");
    scanf("%d",&n);


    // Reading the matrix
    for (int i=0;i<n;i++){
        
        printf("Enter Elements of Row %d \n",i+1);
        for (int j=0;j<4;j++){
            scanf("%d",&a[i][j]); 
        }  
    }

    //Pinting the matrix
    printf("The Matrix is \n");
    for (int i=0;i<n;i++){
        for (int j=0;j<4;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    

    // Converting to hexadecimal and printing

    for (int i=0;i<n;i++){
        
        int sum=0;
        
        for (int j=0;j<4;j++){
            sum=sum+a[i][j]*pow(2,3-j);
        }

        if (sum<10){
            printf("%d \n",sum);
        }
        else{
            printf("%c\n",sum+55);
        }    
    }
    
}