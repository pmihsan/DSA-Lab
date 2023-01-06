#include<stdio.h>
int fibo(int n);
int main()
{
int n,result;
printf("Enter which fibonacci term you want to  calculate\n");
scanf("%d",&n);
result = fibo(n);
printf("The %d fibonacci term is %d\n",n,result);
return 0;
}
int fibo(int n){
if(n <= 1){
	return 1;
}
return fibo(n-1)+fibo(n-2);
}
