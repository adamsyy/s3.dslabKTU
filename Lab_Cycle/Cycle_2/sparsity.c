#include<stdio.h>

void main(){
    int a[3]={62,24,73};
    int p=3;
    printf("%d",p);
   testahne(&p);
   printf("%d",p);
}

void testahne(int* arr){
*arr=*arr+1;
}


