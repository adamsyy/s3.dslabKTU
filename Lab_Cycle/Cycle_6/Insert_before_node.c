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
//insert before specific node
void insert_before_node(int data, int data_before){
    struct DLL *temp = head;
    while(temp != NULL){
        if(temp->data == data_before){
            struct DLL *ptr = (struct DLL *)malloc(sizeof(struct DLL));
            ptr->data = data;
            ptr->next = temp;
            ptr->prev = temp->prev;
            temp->prev = ptr;
            if(ptr->prev != NULL){
                ptr->prev->next = ptr;
            }
            else{
                head = ptr;
            }
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
        int data, data_before;
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        printf("Enter the data after which you want to insert: ");
        scanf("%d", &data_before);
        insert_before_node(data, data_before);
        //PRINT ELEMENTS OF NODE
        struct DLL *temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }

    }