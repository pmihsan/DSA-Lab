#include<stdio.h>  
#define MAX 10  
int stack1[MAX], stack2[MAX];  
int top1=-1, top2=-1;   
int count=0;  
void push1(int data)  
{  
 if(top1 == MAX-1)  
{  
   printf("Stack-1 Overflow\n");  
}  
else  
{  
   top1++;    
   stack1[top1] = data;   
}  
}  
int pop1()  
{  
if(top1 == -1)  
{  
   printf("Stack-1 Underflow\n");  
}  
else  
{  
   int a = stack1[top1];    
   top1--; 
   return a;   
}  }   
void push2(int x)  
{   
if(top2 == MAX-1)  
{  
   printf("Stack-2 Overflow\n");  
}  
else  
{  
    top2++;    
    stack2[top2] = x;   
}  }   
int pop2()  
{  
   int element = stack2[top2];   
   top2--;   
   return element;  
}  
void enqueue(int x)  
{  
    push1(x);  
    count++;  
} 
void dequeue()  
{  
   if((top1==-1) && (top2==-1))  
{  
   printf("Queue is empty\n");  
}  
else  
{  
  for(int i=0;i<count;i++)  
  {  
     int element = pop1();  
     push2(element);  
  }  
int b = pop2();  
printf("The dequeued element is %d\n", b);   
count--;  
for(int i=0;i<count;i++)  
{  
   int a = pop2();  
   push1(a);   
}  }}   
void display()  
{  
    printf("Displaying the Queue\n");
    if(top1 == -1){
	    printf("Queue is Empty\n");
    }
   for(int i=0;i<=top1;i++)  
  {  
     printf("%d\n", stack1[i]);  
  }  
}  
void main()  
{  
    int i = 1,r,data;
    printf("Queue Implementation Using Two Stacks\n");
    while(i){
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice\n");
        scanf("%d",&r);
        if(r == 1){
            printf("Enter an element to insert\n");
            scanf("%d",&data);
            enqueue(data);
        }
        else if(r == 2){
            dequeue();
        }
        else if(r == 3){
            display();
        }
        else if(r == 4){
            printf("Program Ended\n");
            i = 0;
        }
        else{
            printf("Enter a valid choice\n");
        }
    }  
}
