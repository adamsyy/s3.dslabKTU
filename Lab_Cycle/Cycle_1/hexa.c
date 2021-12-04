#include<stdio.h>
int main(){
    int n,a[30][30],i,j,k;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<4;j++){
            printf("Enter the number: ");
            scanf("%d",&a[i][j]);
        }
    }
    int sum;
    for(i=0;i<n;i++){
        sum=0;
        k=1;
        for(j=0;j<4;j++){
            
           sum+=a[i][j]*k;
           k=k*2;
            
        }
           if(sum>9){
            if(sum==10){
                printf("A\n");
            }
            else if(sum==11){
                printf("B\n");
            }
            else if(sum==12){
                printf("C\n");
            }
            else if(sum==13){
                printf("D\n");
            }
            else if(sum==14){
                printf("E\n");
            }
            else if(sum==15){
                printf("F\n");
            }
           }
           else{
               printf("%d\n",sum);
           }}
}
    
