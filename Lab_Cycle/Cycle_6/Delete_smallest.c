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

//delete smallest node
void delete_smallest(){
    struct DLL *temp = head;
    struct DLL *smallest = head;
    while(temp != NULL){
        if(temp->data < smallest->data){
            smallest = temp;
        }
        temp = temp->next;
    }
    if(smallest->prev != NULL){
        smallest->prev->next = smallest->next;
    }
    if(smallest->next != NULL){
        smallest->next->prev = smallest->prev;
    }
    free(smallest);
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
        delete_smallest();
        //PRINT ELEMENTS OF NODE
        struct DLL *temp1 = head;
        while(temp1 != NULL){
            printf("%d ", temp1->data);
            temp1 = temp1->next;
        }

    }