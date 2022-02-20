#include <stdio.h>
#include <stdlib.h>

struct DLL{
    int data;
    struct DLL *next;
    struct DLL *prev;

};

struct DLL *head = NULL;

void insertion_last()  
{  
   struct DLL *ptr,*temp;  
   int item;  
   ptr = (struct DLL *) malloc(sizeof(struct DLL));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          }  
             
       }  
     printf("\nnode inserted\n");  
    }  
//delete node given data
void delete_node(int data){

    struct DLL *temp = head;
    while(temp != NULL){
        if(temp->data==data){
            //delete node
            if(temp->prev != NULL){
                temp->prev->next = temp->next;
            }
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }   
            else{
                head = NULL;
            }
        } 
    }
}

    void main(){
        int n;
        printf("Enter the number of nodes you want to insert: ");
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            insertion_last();
        }
        //PRINT ELEMENTS OF NODE
        struct DLL *temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");   
        printf("enter data to be deleted");
        int data;
        scanf("%d",&data);
        delete_node(data);
        printf("\n");
        temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }

    }