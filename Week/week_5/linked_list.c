#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
}*head,*temp;
void createList(int n);
void displayList();
void InsertBegining();
void InsertEnd();
void DeleteBegining();
void DeleteEnd();
void InsertAfterPosition(int n);
void DeleteAtGivenLocation(int n);
void main()
{
int i = 1,n,r,res,value;
head = NULL;
while(i){
printf("\nLINKED LIST\n1.Create List\n2.Insert data\n3.Delete data\n4.Display List\n5.Exit\n");
printf("Enter your choice\n");
scanf("%d",&r);
switch(r){
    case 1:{
    printf("Enter how many nodes you want to create\n");
    scanf("%d",&n);
    createList(n);
    break;
    }
    case 2:{
    printf("1.Insert at begining\n2.Insert at end\n3.Insert at any position\n");
    scanf("%d",&res);
    if(res == 1){
        InsertBegining();
    }
    else if(res == 2){
        InsertEnd();
    }
    else{
        InsertAfterPosition(n);
    }
    break;
    }
    case 3:{
    printf("1.Delete at begining\n2.Delete at end\n3.Delete at any position\n");
    scanf("%d",&res);
    if(res == 1){
        DeleteBegining();
    }
    else if(res == 2){
        DeleteEnd();
    }
    else{
        DeleteAtGivenLocation(n);
    }

    break;
    }
    case 4:{
    displayList();
    break;
    }
    default:{
    printf("Program Ended\n");
    i = 0;
    break;
    }
}
}
}

void createList(int n){
int i = 1;
struct node *newNode;

while(i <= n){
newNode = (struct node *)malloc(sizeof(struct node));
printf("Enter data to insert in position %d\n",i);
scanf("%d",&newNode->data);
newNode->next = NULL;
if(head == NULL){
head = temp = newNode;
}
else{
temp->next = newNode;
temp = newNode;
}
i++;
}
printf("\n%d Nodes created Successfully\n",n);
}


void displayList(){
printf("\nDisplaying the list\n");
temp = head;
if(temp == NULL){
    printf("\nList is Empty\n");
}
while(temp != 0){
	printf("%d\n",temp->data);
	temp = temp->next;

}
}
void InsertBegining(){
struct node *newNode;
newNode = (struct node *)malloc(sizeof(struct node));
printf("Enter the data to insert in the begining\n");
scanf("%d",&newNode->data);
newNode->next = head;
head = newNode;
printf("Data inserted Successfully\n");
}
void InsertEnd(){
struct node *newNode;
newNode = (struct node *)malloc(sizeof(struct node));
printf("Enter the data to insert at the end\n");
scanf("%d",&(newNode->data));
temp = head;
newNode->next = NULL;
while(temp->next != NULL){
temp = temp->next;
}
temp->next = newNode;
printf("Data inserted Successfully\n"); 
}


void DeleteBegining(){
printf("\nDeleting data from the begining\n");
temp = head;
head = head->next;
free(temp);
printf("Data deleted Successfully\n");
}


void DeleteEnd(){
printf("\nDeleting data from the end\n");
struct node *prevNode;
temp = head;
while(temp->next != NULL){
prevNode = temp;
temp = temp->next;
}
if(temp == head){
head = NULL;
}
else{
   prevNode->next = NULL;
}
free(temp);
printf("Data deleted Successfully\n");
}


void InsertAfterPosition(int n){
int pos,i=1;
struct node *newNode;
printf("Enter the position after which you want to insert the data\n");
scanf("%d",&pos);
if(pos > 0 && pos <= n){
temp = head;
while(i < pos){
temp = temp->next;
i++;
}
newNode = (struct node *)malloc(sizeof(struct node));
printf("Enter the data to insert in the position %d\n",pos+1);
scanf("%d",&newNode->data);
newNode->next = temp->next;
temp->next = newNode;
printf("Data inserted Successfully\n");
} 
else{
printf("Invalid Position\n");
}
}


void DeleteAtGivenLocation(int n){
struct node *nextNode;
int pos,i = 1;
temp = head;
printf("Enter the position to delete the data\n");
scanf("%d",&pos);
if(pos > 0 && pos <= n){
while(i < pos-1){
temp = temp->next;
i++;
}
nextNode = temp->next;
temp->next = nextNode->next;
free(nextNode);
printf("Data deleted Successfully\n");
}
else{
printf("Invalid Position\n");
}
}


