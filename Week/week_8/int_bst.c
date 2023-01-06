#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  

struct node{  
    int data;  
    struct node *left;  
    struct node *right;  
}*root= NULL;  
   
struct node* createNode(int data){  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));   
    newNode->data= data;  
    newNode->left = NULL;  
    newNode->right = NULL;  
    return newNode;  
}  

void insert(int data) {  
    struct node *newNode = createNode(data);   
    if(root == NULL){  
        root = newNode;  
        return;  
      }  
    else {   
        struct node *current = root, *parent = NULL;     
        while(true) {    
            parent = current;   
            if(data < current->data) {  
                current = current->left;  
                if(current == NULL) {  
                    parent->left = newNode;  
                    return;  
                }  
            }  
           
            else {  
                current = current->right;  
                if(current == NULL) {  
                    parent->right = newNode;  
                    return;  
                }  
            }  
        }  
    }  
}  
 
void inorder(struct node *node) {         
    if(root == NULL){  
        printf("Tree is empty\n");  
          return;  
     }  
    else {            
        if(node->left!= NULL)  
            inorder(node->left);  
        printf("%d ", node->data);  
        if(node->right!= NULL)  
          inorder(node->right);  
            
    }        
} 
void postorder(struct node *node) {         
    if(root == NULL){  
        printf("Tree is empty\n");  
          return;  
     }  
    else {            
        if(node->left!= NULL)  
            postorder(node->left);   
        if(node->right!= NULL)  
          postorder(node->right); 
        printf("%d ", node->data);  
    }        
}  

void preorder(struct node *node) {         
    if(root == NULL){  
        printf("Tree is empty\n");  
          return;  
     }  
    else { 
        printf("%d ", node->data);             
        if(node->left!= NULL)  
            preorder(node->left);   
        if(node->right!= NULL)  
          preorder(node->right); 
    }        
} 

void main(){
    int n,data;
    printf("Binary Search Tree\nEnter the number of nodes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the data %d\n",i+1);
        scanf("%d",&data);
        insert(data);
    }
    printf("Inorder Traversal of Binary Search Tree\n");
    inorder(root);
    printf("\nPreorder Traversal of Binary Search Tree\n");
    preorder(root);
    printf("\nPostOrder Traversal of Binary Search Tree\n");
    postorder(root);
    printf("\n");
}
