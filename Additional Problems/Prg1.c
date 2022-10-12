// Program 1: Program to rotate an array

#include<stdio.h>

int rotate(int arr[],int n,char d,int cr){

    // rotating towards left
    if (d=='l'){                        

        int temp[100];

        //first part of temp array
        int j=0;
        for (int i=cr;i<n;i++){
            temp[j]=arr[i];
            j++;
        }

        //second part of temp array 
        for (int i=0;i<cr;i++){
            temp[j]=arr[i];
            j++;
        }

        // Modifying the array
        for (int i=0;i<n;i++){
            arr[i]=temp[i];
        }
    }

    // rotating towards right
    else if (d=='r'){       
        int i,j;
        for (i = 0; i < cr; i++){

            int last=arr[n-1];
            for (j=n-1;j>0;j--){
                
                arr[j]=arr[j-1];
            }
            arr[0]=last;
        }
        
    }
    else{
        printf("!Enter Valid options!");
    }
    
}

//MAIN FUNCTION
int main(){
    
    int n;
    int arr[100];
    printf("Enter the Total Number of Elements: ");
    scanf("%d",&n);

    printf("Enter the elements:\n");
    for (int i=0;i<n;i++){
        
        printf("Enter the element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    
    char d;
    printf("Enter the direction of rotation(l-left/r-right): ");
    getchar();
    scanf("%c",&d);
    
    int cr;
    printf("Enter the number of rotation: ");
    scanf("%d",&cr);

    rotate(arr,n,d,cr);

    //PRINTING THE ARRAY
    printf("The Rotated Array is:  ");
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
}