#include<stdio.h>

void main(){
  int arr[]={1,23,3,4,5};
 set(&arr);
 printf("%d",*arr);
}

void set(int *arr){
arr=55;
}