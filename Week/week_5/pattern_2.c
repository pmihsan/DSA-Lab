#include<stdio.h>
#include<string.h>
void main()
{
char arr[50];
int res = 0,count_a=0,count_b=0;
printf("Enter your string\n");
scanf("%s",arr);
if(arr[0] == 'A'){
        res = 1;
    }
for(int i=0;i<strlen(arr);i++){
    if(arr[i] == 'A'){
        count_a++;
    }
    if(arr[i] == 'B'){
        count_b++;
    }
}
if(res && count_a == count_b+1){
    printf("String is of the given pattern A^(n+1) B^n\n");
}
else{
    printf("String is not of the given pattern A^(n+1) B^n\n");
}
}
