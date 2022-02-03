#include<stdio.h>
char arr[101];
int top=-1;


void main(){
 
push('3');
push('2');
push('5');
display();
}

void push(char item){
    if(top==100){
        printf("full ai");
        return;
    }
    //arr[++top]=item;
    if(item=='('||item=='{'||item=='['){
        arr[++top]=item;
    }
}

int pop(){
    if(top==-1){printf("underflow"); return;}
//return arr[top--];
if(arr[top--]==)
}

void display(){
    for(int i=top;i>=0;i--){
        printf("%c",arr[i]);
    }
}
