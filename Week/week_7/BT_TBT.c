#include<stdio.h>
#include<stdlib.h>
#define ARRSIZE 9
struct node {
    char data;
    struct node *left,*right;
    int isThreaded;
}* root = NULL;
struct node *convert(struct node *p){
    if(!p || (p->left == NULL && p->right == NULL)){
        return p;
    }
    if(p->left != NULL){
        struct node *temp = convert(p->left);
        temp->right = p;
        temp->isThreaded = 1;
    }
    if(p->right == NULL){
        return p;
    }
    return convert(p->right);
}
struct node *in_succ(struct node *p){
    if(p->isThreaded){
        return p->right;
    }
    p = p->right;
    while(p && p->isThreaded == 0 && p->left){
        p = p->left;
    }
    return p;
}
void inorder(struct node *p){
    if(!p){
        printf("Tree is empty\n");
        return;
    }
    printf("Inorder Traversal\n");
    while(p && p->isThreaded == 0 && p->left){
        p = p->left;
    }
    while(p){
        printf("%c ",p->data);
        p = in_succ(p);
    }
    printf("\n");
}
int main(){
    root = (struct node *)malloc(sizeof(struct node));
    root->data = 'A';
    root->isThreaded  = 0;
    struct node *nodes[ARRSIZE];
    for(int i=0;i<ARRSIZE;i++){
        nodes[i] = (struct node *)malloc(sizeof(struct node));
        nodes[i]->isThreaded = 0;
        nodes[i]->data = 'B' + i;
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }
    root->left = nodes[0];
    root->right = nodes[1];
    nodes[0]->left = nodes[2];
    nodes[0]->right = nodes[3];
    nodes[1]->left = nodes[4];
    nodes[1]->right = nodes[5];
    nodes[2]->left = nodes[6];
    nodes[2]->right = nodes[7];
    nodes[4]->right = nodes[8];
    convert(root);
    inorder(root);
    return 0;
}
