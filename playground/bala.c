char peek();
void push(char);
char pop();
#include<string.h>
#include<stdio.h>
char arr[101];
int check=0;
int top=-1;


void main(){
  //printf("%d",top);
push('( ');
 //printf("%d",top);
push('(');
 //printf("%d",top);
push(')');
 //printf("%d",top);
push('(');
push(')');
push(')');
push(')');
    //printf("%d",top);

if(top==-1&&check==0){ 
    printf("balanced");}
   else{
printf("not balanced");
   } 

}
char peek(){
     if(top==-1){ check=1;
        return 'p';}
    
return arr[top];
}
char pop(){
    if(top==-1){ return -1;}
return arr[top--];
//if(arr[top--]== )
}
void push(char item){
    if(top==100){
        check=1;
        printf("full ai");
        return;
    }
    //arr[++top]=item;
    if(item=='('||item=='{'||item=='['){
        arr[++top]=item;
        
    }
    if(item==')'&&peek()=='('){
    pop();
    }
    if(item=='}'&&peek()=='{'){
    pop();
    }
    if(item==']'&&peek()=='['){
    pop();
    }

}





// void checkin(){
//     for(int i=top;i>=0;i--){
// if()
//     }
// }

// void display(){
//     for(int i=top;i>=0;i--){
//         printf("%c",arr[i]);
//     }
// }
