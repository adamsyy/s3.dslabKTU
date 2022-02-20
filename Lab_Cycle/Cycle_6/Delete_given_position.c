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
//delete node given position
void delete_node(int position){
    struct DLL *temp = head;
    int i;
    for(i=0;i<position-2;i++){
        temp = temp->next;
    }
    struct DLL *ptr = temp->next;
    temp->next = ptr->next;
    if(ptr->next != NULL){
        ptr->next->prev = temp;
    }
    free(ptr);
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
        int position;
        printf("Enter the position of node you want to delete: ");
        scanf("%d", &position);
        delete_node(position);
        //PRINT ELEMENTS OF NODE
        struct DLL *temp1 = head;
        while(temp1 != NULL){
            printf("%d ", temp1->data);
            temp1 = temp1->next;
        }

    }