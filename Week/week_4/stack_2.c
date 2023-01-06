#include<stdio.h>
#include<string.h>
#define ARRSIZE 10
struct stack{
     char stack[ARRSIZE];
     int top;
}S;
int push(struct stack *,char);
char pop(struct stack *);
int isEmpty(struct stack);
int isFull(struct stack);
void reverse(struct stack *);
void insertBottom(struct stack *,char);

void main()
{
    int n,k=0,i=1;
    char x,stack_arr[ARRSIZE];
    S.top = 0;
    printf("Enter your string and then press Enter\n");
    while(i){
          x = getchar();
          if(x == '\n'){
              break;
          }
          if(!push(&S,x)){
              printf("Stack overflow Push failed\n");
          }
    }
    S.stack[S.top] = '\0';
    strcpy(stack_arr,S.stack);
     reverse(&S);
     printf("\nYour string  is %s\n",stack_arr);
     printf("\nReversed string is %s\n",S.stack); 
     if(!strcmp(stack_arr,S.stack)) {
         printf("\nString is Palindrome\n\n");
     }
     else{
         printf("\nString is not Palindrome\n\n");
     }
}
int isEmpty(struct stack s){
    if(s.top == 0){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack s){
    if(s.top == ARRSIZE){
        return 1;
    }
    else{
        return 0;
    }
}
int push(struct stack *s,char x){
    if(isFull(*s)){
        return 0;
    }
    s->stack[s->top] = x;
    s->top++;
    return 1;
}
void reverse(struct stack *s){
    if(s->top == 0){
        return;
    }
    char item = pop(s);
    reverse(s);
    insertBottom(s,item);
}
char pop(struct stack *s){
    if(isEmpty(*s)){
        return '\0';
    }
    char x = s->stack[s->top - 1];
    s->stack[s->top - 1] = '\0';
    s->top--;
    return x;
}
void insertBottom(struct stack *s,char x){
    if(s->top == 0){
        push(s,x);
        return;
    }
    char c = pop(s);
    insertBottom(s,x);
    push(s,c);
}
