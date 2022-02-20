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
//insert after specific node
void insert_after_node(int data, int data_after){
    struct DLL *temp = head;
    while(temp != NULL){
        if(temp->data == data_after){
            struct DLL *ptr = (struct DLL *)malloc(sizeof(struct DLL));
            ptr->data = data;
            ptr->next = temp->next;
            ptr->prev = temp;
            temp->next = ptr;
            if(ptr->next != NULL){
                ptr->next->prev = ptr;
            }
            break;
        }
        temp = temp->next;
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
        int data, data_after;
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        printf("Enter the data after which you want to insert: ");
        scanf("%d", &data_after);
        insert_after_node(data, data_after);
        printf("\n");
        temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }

    }