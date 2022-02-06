#include<stdio.h>

void lol(int arr[2][1]){
arr[2][0]=99;
}

void main(){
    printf("hehe");
    int arr[2][1]={0};
lol(arr);
printf("%d",arr[2][0]);
}