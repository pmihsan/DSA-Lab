#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
}*head;
void createList(int n);
void insertAtPosition(int pos,int data);
void displayList();
int main(){
int n,data,pos;
printf("Enter the number of nodes\n");
scanf("%d",&n);
createList(n);
printf("Displaying the list\n");
displayList();
printf("\n");
/*printf("Enter the data to insert at any position\n");
scanf("%d",&data);
printf("Enter which position you want to insert\n");
scanf("%d",&pos);
insertAtPosition(pos,data);
printf("Displaying the list\n");
displayList();*/
return 0;
}
void createList(int n){
	struct node *newNode, *temp;
	int data,i;
	head = (struct node *)malloc(sizeof(struct node));
	if(head == NULL){
		printf("Unable to  allocate memory\n");
	}
	else{
		printf("Enter the data of node 1\n");
		scanf("%d",&data);
		head->data = data;
		head->next = NULL;
		temp = head;
		for(i=2;i<=n;i++){
			newNode = (struct node *)malloc(sizeof(struct node));
			if(newNode == NULL){
				printf("Unable to allocate memory\n");
				break;
			}
			else{
				printf("Enter the data of node %d\n",i);
				scanf("%d",&data);
				newNode->data = data;
				newNode->next = NULL;
				temp->next = newNode;
				temp = temp->next;
			}
	        }
		printf("Singly Linked List Created\n\n");
	}

}
void insertAtPosition(int pos,int data){

}
void displayList(){
	struct node *temp;
	if(head == NULL){
	       printf("List is already empty\n");
	}
	else{
		temp = head;
		while(temp != NULL){
			printf("Data = %d\n",temp->data);
			temp = temp->next;
		}	
	}
}	
