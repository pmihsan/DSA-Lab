#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  

struct node{  
    int data;  
    struct node *left;  
    struct node *right;  
}*rootTree1 = NULL,*rootTree2 = NULL;        

struct node* createNode(int data){  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data= data;  
    newNode->left = NULL;  
    newNode->right = NULL;      
    return newNode;  
}      

bool isIdenticalStructure(struct node *root1, struct node *root2) {  
    if(root1 == NULL && root2 == NULL)  
          return true;  

    if(root1 != NULL  && root2 != NULL) {     
          return ( (root1 && root2) && (isIdenticalStructure(root1->left, root2->left)) &&  
                  (isIdenticalStructure(root1->right, root2->right)) );  
    }  
    return false;  
}  

void inorder(struct node *node) {         
    if(rootTree1 == NULL || rootTree2 == NULL){  
        printf("Tree is empty\n");  
          return;  
     }  
    else {            
        if(node->left!= NULL)  
            inorder(node->left);  
        printf("%d   ", node->data);  
        if(node->right!= NULL)  
          inorder(node->right);        
    }        
}        

int main()  
{  
	//Creating simple BST 1 
    rootTree1 = createNode(10);  
    
    rootTree1->left = createNode(5);    
    rootTree1->left->left = createNode(4);
   //In output the below line with create node data 6 is commented to show that they are structurally similar
    rootTree1->left->right = createNode(6);

    rootTree1->right = createNode(15);   
    rootTree1->right->left = createNode(14);  
    rootTree1->right->right = createNode(16);  

    //Creating simple BST 2
    rootTree2 = createNode(20);  
    
    rootTree2->left = createNode(10);   
    rootTree2->left->left = createNode(5); 

    rootTree2->right = createNode(30);  
    rootTree2->right->left = createNode(25);  
    rootTree2->right->right = createNode(35);  

    printf("Inorder traversal of Binary Search Tree 1\n");
    inorder(rootTree1);
    printf("\n");
    printf("\nInorder traversal of Binary Search Tree 2\n");
    inorder(rootTree2);
    printf("\n");
 
    if(isIdenticalStructure(rootTree1, rootTree2))  
        printf("\nBoth the binary search trees are STRUCTURALLY IDENTICAL\n");  
    else  
        printf("\nBoth the binary search trees are NOT STRUCTURALLY IDENTICAL\n");  
 
    return 0;  
}  
