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
///insert at a specific position
void insert_at_position(int data, int position){
    struct DLL *temp = head;
    int i = 1;
    while(temp != NULL){
        if(i == position){
            struct DLL *ptr = (struct DLL *)malloc(sizeof(struct DLL));
            ptr->data = data;
            ptr->next = temp;
            ptr->prev = temp->prev;
            temp->prev = ptr;
            if(ptr->prev != NULL){
                ptr->prev->next = ptr;
            }
            break;
        }
        temp = temp->next;
        i++;
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
        int data, position;
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        printf("Enter the position after which you want to insert: ");

        scanf("%d", &position);
        insert_at_position(data, position);
        temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }

    }