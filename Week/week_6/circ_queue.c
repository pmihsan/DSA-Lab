#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
struct node1
{
	char data[MAX];
	struct node1 *next;
}*front = NULL,*rear = NULL;
struct node2
{
	char data[MAX];
	struct node2 *next;
}*front2 = NULL,*rear2 = NULL;

void enqueue1(char d[]) 
{
	struct node1 *newNode;
	newNode = (struct node1 *)malloc(sizeof(struct node1));
    strcpy(newNode->data,d);
	newNode->next = NULL;
	if((rear==NULL)&&(front==NULL))
	{
		front = rear = newNode;
		rear->next = front;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
		newNode->next = front;
	}
} 
void enqueue2(char d[]) 
{
	struct node2 *newNode;
	newNode = (struct node2 *)malloc(sizeof(struct node2));
	strcpy(newNode->data,d);
	newNode->next = NULL;
	if((rear2==NULL)&&(front2==NULL))
	{
		front2 = rear2 = newNode;
		rear2->next = front2;
	}
	else
	{
		rear2->next = newNode;
		rear2 = newNode;
		newNode->next = front2;
	}
} 
void print1(){ 
	struct node1 *t;
	t = front;
	if((front==NULL)&&(rear==NULL))
		printf("Queue is Empty\n");
	else{
		do{
			printf("%s\n",t->data);
			t = t->next;
		}while(t != front);
	}
}
void print2(){ 
	struct node2 *t;
	t = front2;
	if((front2==NULL)&&(rear2==NULL))
		printf("Queue is Empty\n");
	else{
		do{
			printf("%s\n",t->data);
			t = t->next;
		}while(t != front2);
	}
}
int main()
{
	int n;
    char data[MAX];
	printf("Enter the no of students in section 1\n");
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
		printf("Enter the student %d name of section 1\n",i);
        scanf("%s",data);
        if(!strcmp(data,"Raja") || !strcmp(data,"Prabhu") || !strcmp(data,"Indiran") || !strcmp(data,"Chandiran") ){
            enqueue1(data);
        }
        else{
            enqueue2(data);
        }
    }
    printf("\nEnter the no of students in section 2\n");
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
		printf("Enter the student %d  name of section 2\n",i);
        scanf("%s",data);
        if(!strcmp(data,"Raja") || !strcmp(data,"Prabhu") || !strcmp(data,"Indiran") || !strcmp(data,"Chandiran") ){
            enqueue1(data);
        }
        else{
            enqueue2(data);
        }
    }
    printf("\nPrinting the Boys Section\n");
    print1();
    printf("\n");
    printf("Printing the Girls Section\n");
    print2();
    printf("\n");
return 0;
}
