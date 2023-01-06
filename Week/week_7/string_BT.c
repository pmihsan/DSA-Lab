/*
Create a Binary tree of strings, such that the string at root is “ROOT” (by default) and keep all the 
string that starts with vowels as left children and consonants as right children and display the 
result in “In order”.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ARRSIZE 50

struct node{
    char data[ARRSIZE];
    struct node *left;
    struct node *right;
}*root = NULL;

int isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return 1;
    }
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return 1;
    }
    return 0;
}

void InOrder(struct node *root){
    if(!root){
        return;
    }
    InOrder(root->left);
    printf("%s ",root->data);
    InOrder(root->right);
}
void setroot(){
    root = (struct node *)malloc(sizeof(struct node));
    char arr[] = "ROOT";
    strcpy(root->data,arr);
    root->left = NULL;
    root->right = NULL;
}
void input(char *str){
    fgets(str,ARRSIZE,stdin);
    int len = strlen(str);
    if(str[len-1] == '\n'){
        str[len-1] = '\0';
    }
}
void insert(struct node *ptr){
    struct node *p = root;
    if(isVowel((ptr->data)[0])){
        while(p->left){
            p = p->left;
        }
        p->left = ptr;
    }
    else{
        while(p->right){
            p = p->right;
        }
        p->right = ptr;
    }
}
void main(){
    setroot();
    int n;
    struct node *temp;
    printf("Enter how many string you are going to give\n");
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
    printf("Enter the new string\n");
    temp = (struct node *)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    input(temp->data);
    insert(temp);
    }
    printf("InOrder traversal of the Binary Tree\n");
    InOrder(root);
    printf("\n");
}

