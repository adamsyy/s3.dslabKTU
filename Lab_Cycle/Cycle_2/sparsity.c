#include<stdio.h>
typedef struct{
    int row;
    int col;
    int value;
}term;
 



void main(){
   int size;
     printf("enter no of non zero elements");
     scanf("%d",&size);
     term a[size];
     a[0].value=size;
  printf("enter number of row and col");
  scanf("%d%d",&a[0].row,&a[0].col);
   
  for(int i=1;i<=a[0].value;i++){
       printf("enter %dth non zero element in the format row,col,value",i);
    scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].value);
  }

}



