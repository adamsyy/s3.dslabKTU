// Program 2: Mean Median Mode

#include<stdio.h>


// Function to calculate MEAN
float mean(int arr[],int n){

    float sum=0.0;
    for (int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    
    float m=sum/n;
    printf("Mean= %f \n",m);
}

//Sorting
int bubblesort(int arr[],int n){

    int temp,i,j;
    for (i=0;i<n-1;i++){
        
        for (j=0;j<n-1-i;j++){

            if (arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j+1]=temp;
            }  
        }  
    } 
}

// Function to find MEDIAN
float median(int arr[],int n){

    bubblesort(arr,n);

    float m;
    int x1,x2,x;
    if (n%2==0){
        x1=(n/2)-1;
        x2=n/2;
        m =(arr[x1]+arr[x2])/2.0;
    }
    else{

        x=((n+1)/2)-1;
        m=arr[x];
    }
    
    printf("Median = %f \n",m);
}

// Function to find MODE
int mode(int arr[],int n){

    int m=0,maxcount=1,i,j;

    for (i = 0; i < n; i++){
        
        int count=0;
        for (j=i+1;j<n;j++){
            
            if (arr[i]==arr[j]){
                count++;
            }  
        }

        if (count>maxcount){
            maxcount=count;
            m=arr[i];
        }
        if (count==maxcount){
            m=0;
        }
         
    }

    printf("Mode = %d \n",m);
    if (m==0){
        printf("No Mode\n");
    }
}

//MAIN Function
int main(){

    int n,arr[100];

    printf("Enter the Total Number of Elements: ");
    scanf("%d",&n);


    // Reading the array
    printf("Enter the Elements int the array:\n");
    for (int i = 0; i < n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    
    //Mean
    mean(arr,n);

    //Median
    median(arr,n);

    //Mode
    mode(arr,n);
}