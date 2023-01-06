#include <stdio.h>  
#include <stdlib.h>  
typedef enum {false,true} boolean;  
struct node *in_succ(struct node *p);   
struct node *insert(struct node *root, int data);  
void inorder( struct node *root);  
void preorder( struct node *root);  
struct node  
{  
        struct node *left;  
        boolean lthread;  
        int info;  
        boolean rthread;  
        struct node *right;  
}; 
int main( )  
{  
    int choice,num;  
        struct node *root=NULL;  
        while(1)  
        {  
           printf("\nOperations in Threaded Binary Tree in C\n");  
                printf("1.Insert\n");  
                printf("2.Inorder Traversal\n");  
                printf("3.Preorder Traversal\n");  
                printf("4.Quit\n");  
                printf("\nEnter your choice : ");  
                scanf("%d",&choice);  
                switch(choice)  
                {  
                 case 1:  
                        printf("Enter the number to be inserted : \n");  
                        scanf("%d",&num);  
                        root = insert(root,num);  
                        break;  
                 case 2:  
                        inorder(root);  
                        break;  
                 case 3:  
                        preorder(root);  
                        break;  
                 case 4:  
                         exit(1);  
  
                 default:  
                        printf("\nWrong choice\n");  
        }  
    }  
        return 0;  
}  
struct node *insert(struct node *root, int data)  
{  
    struct node *tmp,*par,*ptr;  
    int found=0;  
    ptr = root;  
    par = NULL;  
    while( ptr!=NULL )  
    {  
        if(data == ptr->info)  
        {  
            found =1;  
            break;  
        }  
        par = ptr;  
        if(data < ptr->info)  
        {  
            if(ptr->lthread == false)  
                ptr = ptr->left;  
            else  
                break;  
        }  
        else  
        {  
            if(ptr->rthread == false)  
                ptr = ptr->right;  
            else  
                break;  
        }  
    }  
    if(found)  
        printf("Duplicate key\n");  
    else  
    {  
        tmp=(struct node *)malloc(sizeof(struct node));  
        tmp->info=data;  
        tmp->lthread = true;  
        tmp->rthread = true;  
        if(par==NULL)  
        {  
            root=tmp;  
            tmp->left=NULL;  
            tmp->right=NULL;  
        }  
        else if( data < par->info )  
        {  
            tmp->left=par->left;  
            tmp->right=par;  
            par->lthread=false;  
            par->left=tmp;  
        }  
        else  
        {  
            tmp->left=par;  
            tmp->right=par->right;  
            par->rthread=false;  
            par->right=tmp;  
        }  
    }  
    return root;  
}  

struct node *in_succ(struct node *ptr)  
{  
        if(ptr->rthread==true)  
                return ptr->right;  
        else  
        {  
                ptr=ptr->right;  
                while(ptr->lthread==false)  
                        ptr=ptr->left;  
                return ptr;  
        }  
} 

void inorder( struct node *root)  
{  
        struct node *ptr;  
        if(root == NULL )  
        {  
                printf("Tree is empty\n");  
                return;  
        } 
        printf("Inorder Traversal of the Threaded Binary tree is\n"); 
        ptr=root;  
        while(ptr->lthread==false)  
                ptr=ptr->left;  
        while( ptr!=NULL )  
        {  
                printf("%d ",ptr->info);  
                ptr=in_succ(ptr);  
        }
        printf("\n");  
}  
void preorder(struct node *root )  
{  
        struct node *ptr;  
        if(root==NULL)  
        {  
                printf("Tree is empty\n");  
                return;  
        }  
        printf("Preorder Traversal of the Threaded Binary tree is\n");
        ptr=root;  
        while(ptr!=NULL)  
        {  
                printf("%d ",ptr->info);  
                if(ptr->lthread==false)  
                        ptr=ptr->left;  
                else if(ptr->rthread==false)  
                        ptr=ptr->right;  
                else  
                {  
                        while(ptr!=NULL && ptr->rthread==true)  
                                ptr=ptr->right;  
                        if(ptr!=NULL)  
                                ptr=ptr->right;  
                }  
        } 
        printf("\n"); 
}  
