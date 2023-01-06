#include<stdio.h>
#define ARRSIZE 10
int push(int arr[],int *top);
void pop(int arr[],int *top);
void peek(int arr[],int *top);
void display(int arr[],int *top);
void main(){
    int top = -1,r,res,i=1;
    int stack[ARRSIZE] = {4,2,7,4,3,1,8,9} ;
    top = 7;
    printf("Which operation do you want to perform in a Stack of numbered dinner plates\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n");
     while(i){
    printf("Enter your choice\n");
    scanf("%d",&r);
    switch(r){
        case 1:{
            printf("\nPush operation in the stack of numbered plates\n");
            res = push(stack,&top);
            if(!res) printf("Push operation Failed\n\n");
            break;
        }
        case 2:{
            printf("\nPop operation in the stack of numbered plates\n");
            pop(stack,&top);
            break;
        }
        case 3:{
            printf("\nFinding the peek element in the stack of numbered plates\n");
            peek(stack,&top);
            break;
        }
        case 4:{
            printf("\nDisplaying the stack of numbered plates\n");
            display(stack,&top);
            break;
        }
        default:{
            printf("\nEnter a valid choie\n");
            i = 0;
        }
    }
    }
    printf("Program Ended\n");
}
int push(int stack[],int *top){
    int x,i=0,n;
   /* printf("\nEnter how many elements you want to give(max 10)\n");
    scanf("%d",&n);
    if(n < 0 || n > 10){
        return 0;
    }*/
    //while(i<n){
    printf("Enter the new plate number to insert\n");
    scanf("%d",&x);
    if(*top == ARRSIZE - 1){
        printf("Stack OVERFLOW\n");
        return 0;
    }
    else{
        (*top)++;
        stack[*top] = x;
    }
    //i++;  // }
    printf("Dinner plate added into the stack\n\n");
    return 1; 
}


void pop(int stack[],int *top){
int item;
if(*top == -1){
    printf("\nStack UNDERFLOW - No Elements to POP\n");
}
else{
    printf("\nPopping the top numbered plate of the stack\n");
    item = stack[*top];
    (*top)--;
    printf("%d\n",item);
}
printf("\n");
}


void peek(int stack[],int *top){
    if(*top == -1){
        printf("\nStack is empty(UNDERFLOW)\n");
    }
    else{
        printf("\nThe peek element is %d\n",stack[*top]);
    }
    printf("\n");
}

void display(int stack[],int *top){
    int i;
    if( (*top) == -1 ){
        printf("\nStack is Empty(No Elements to display)\n");
    }
    else{
    for(i = *top;i >= 0;i--){
        printf("%d\n",stack[i]);
    }
    }
    printf("\n");
}
