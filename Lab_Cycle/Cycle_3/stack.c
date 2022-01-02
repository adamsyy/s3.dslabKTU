#include<stdio.h>
int top=-1,item,i,t;
int stack[30];
int size;
int pop(){
    if(top==-1){
        printf("Stack Underflow");
    }
    else{
        return stack[top--];
    }
}
void push(int x){
    if(top>=size-1){
        printf("Stack overflow..");
    }
    else{
        stack[++top]=x;
    }
}
int main(){
    printf("Enter the stack size: ");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("Enter the element: ");
        scanf("%d",&item);
        push(item);
    }
    printf("Enter the number of times popping to be done: ");
    scanf("%d",&t);
    for(i=0;i<t;i++){
        int v=pop();
        printf("%d\t",v);
        
    }
}