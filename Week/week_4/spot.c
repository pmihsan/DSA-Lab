#include<stdio.h>
#include<string.h>
#define ARRSIZE 30
int push(char arr[],int *top);
void pop(char arr[],int *top);
//void pop1(char arr[],int *top);
void peek(char arr[],int *top);
void display(char arr[],int *top);
char stack_pop[ARRSIZE];
int front = 0;
void main(){
    int top = -1,r,res,i=1;
   // char stack[ARRSIZE] = "EAS*Y*QUE***ST*ION";
   char stack[ARRSIZE];
    printf("Which operation do you want to perform in a Stack\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.Display the poped elements of the given stack\n");
     while(i){
    printf("Enter your choice\n");
    scanf("%d",&r);
    switch(r){
        case 1:{
            printf("\nPush operation in the stack\n");
            res = push(stack,&top);
            if(!res) printf("Push operation Failed\n\n");
            break;
        }
        case 2:{
            printf("\nPop operation in the stack\n");
            pop(stack,&top);
            break;
        }
        case 3:{
            printf("\nFinding the peek element in the stack\n");
            peek(stack,&top);
            break;
        }
        case 4:{
            printf("\nDisplaying the stack\n");
            display(stack,&top);
            break;
        }
        case 5:{
            printf("\nDisplaying the POPed elements of the given stack\n");
            for(int k=0;k<front;k++){
                printf("%c\n",stack_pop[k]);
            }
            break;
        }
        default:{
            printf("\nEnter a valid choice\n");
            i = 0;
        }
    }
    }
    printf("Program Ended\n");
}


int push(char stack[],int *top){
    int i=0,n;
    char x, item;
    printf("\nEnter how many characters you want to give(max 30)\n");
    scanf("%d",&n);
    if(n < 0 || n > ARRSIZE){
        return 0;
    }
    while(i<n){
    printf("Enter a character to be insert\n");
    scanf("%c",&x);
    scanf("%c",&x);
    if(*top == ARRSIZE-1){
        printf("Stack OVERFLOW\n");
        return 0;
    }
    
    else{
        
        (*top)++;
        stack[*top] = x;
        if(stack[*top] == '*'){    // printf("%c\n",stack[*top-1]);
            item = stack[*top-1];  // printf("%d\n",*top);
            (*top)--;
            (*top)--;              // printf("%d\n",*top);
            stack_pop[front] = item;
            front++;
        }
    }
    i++;
    }
    printf("Data added into the stack\n\n");
    return 1; 
}

void pop(char stack[],int *top){
char item;
if(*top == -1){
    printf("\nStack UNDERFLOW - No Elements to POP\n");
}
else{
    printf("\nPopping the first element\n");
    item = stack[*top];
    (*top)--;
    printf("%c\n",item);
}
printf("\n");
}


void peek(char stack[],int *top){
    if(*top == -1){
        printf("\nStack is empty(UNDERFLOW)\n");
    }
    else{
        printf("\nThe peek element is %c\n",stack[*top]);
    }
    printf("\n");
}

void display(char stack[],int *top){
    int i;
    if( (*top) == -1 ){
        printf("\nStack is Empty(No Elements to display)\n");
    }
    else{
    for(i = *top;i >= 0;i--){
        printf("%c\n",stack[i]);
    }
    }
    printf("\n");
}


