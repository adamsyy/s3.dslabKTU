#include <stdio.h>
#include <stdlib.h>

struct bst{
    int data;
    struct bst *left;
    struct bst *right;
};
//create a binary search tree
struct bst* create_bst(int data){
    struct bst *new_node = (struct bst *)malloc(sizeof(struct bst));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
//insert a node in the binary search tree
struct bst* insert_bst(struct bst *root, int data){
    if(root == NULL){
        return create_bst(data);
    }
    if(data < root->data){
        root->left = insert_bst(root->left, data);
    }
    else if(data > root->data){
        root->right = insert_bst(root->right, data);
    }
    return root;
}
//print the binary search tree
void print_bst(struct bst *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    print_bst(root->left);
    print_bst(root->right);
}

void main(){
 //do while loop to perform push 
    struct bst *root = NULL;
    int data;
    do{
        printf("Enter the data to be inserted in the binary search tree: ");
        scanf("%d", &data);
        root = insert_bst(root, data);
    }while(data != -1);
    printf("The binary search tree is: ");
    print_bst(root);
}