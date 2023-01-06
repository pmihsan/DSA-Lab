#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  

struct node{  
    char data;  
    struct node *left;  
    struct node *right;  
}*root= NULL;  
   
struct node* createNode(char data){  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));   
    newNode->data= data;  
    newNode->left = NULL;  
    newNode->right = NULL;  
    return newNode;  
}  

void insert(char data) {  
    struct node *newNode = createNode(data);   
    if(root == NULL){  
        root = newNode;  
        return;  
      }  
    else {   
        struct node *current = root, *parent = NULL;     
        while(true) {    
            parent = current;   
            if((int)data < (int)current->data) {  
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

struct node* search(struct node * root,char key)
{
    if (root == NULL || root->data == key)
       return root;
    if ((int)root->data < (int)key)
       return search(root->right, key);
    return search(root->left, key);
}

struct node* minNode(struct node *root) {  
    if (root->left != NULL)  
        return minNode(root->left);  
    else   
        return root;  
} 

struct node* deleteNode(struct node *node, char value) {  
    if(node == NULL){  
          return NULL;  
     }  
    else {   
        if((int)value < (int)node->data)  
            node->left = deleteNode(node->left, value);  
        else if((int)value > (int)node->data)  
            node->right = deleteNode(node->right, value);  
        else {  
            if(node->left == NULL && node->right == NULL)  
                node = NULL;  
              
            else if(node->left == NULL) {  
                node = node->right;  
            }   
            else if(node->right == NULL) {  
                node = node->left;  
            }    
            else {  
                struct node *temp = minNode(node->right);  
                node->data = temp->data;  
                node->right = deleteNode(node->right, temp->data);  
            }  
        }  
        return node;  
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
        printf("%c ", node->data);  
        if(node->right!= NULL)  
          inorder(node->right);  
            
    }        
} 

void main(){
    int n;
    char data;
    printf("Binary Search Tree Operations\nInserting the given Elements\n");
    //M,R,I,L,E,K,O,U,P,R,T,G
    insert('M');
    insert('R');
    insert('I');
    insert('L');
    insert('E');
    insert('K');
    insert('O');
    insert('U');
    insert('P');
    insert('R');
    insert('T');
    insert('G');
    printf("Inorder Traversal of given Binary Search Tree\n");
    inorder(root);
    printf("\n\nInserting Alphabets Q and V");
    insert('Q');
    insert('V');
    printf("\nInorder Traversal After Inserting 'Q' and 'V'\n");
    inorder(root);
    printf("\n\nSearching Element E\n");
    data = 'E';
    struct node * ans = search(root,data);
    if(ans != NULL){
        printf("Element '%c' found in the Tree",data);
    }
    else{
        printf("Element '%c' not found in the Tree",data);
    }
    printf("\n\nInorder Traversal of Altered Binary Search Tree\n");
    inorder(root);
    printf("\n\nDeleting Elements G,O,M\n");
    deleteNode(root,'G');
    deleteNode(roo`t,'O');
    deleteNode(root,'M');
    printf("Inorder Traversal After Deleting G,O,M\n");
    inorder(root);
    printf("\n");
}

