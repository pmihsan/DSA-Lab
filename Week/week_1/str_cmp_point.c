#include<stdio.h>
int main()
{
char str1[20],str2[20],*a,*b;
int check = 0;
printf("Enter your first string\n");
scanf("%s",str1);
printf("Enter your second string\n");
scanf("%s",str2);
a = str1;
b = str2;
while( (*a != '\0')&&(*b != '\0')){
	if(*a != *b){
		check = 1;
	}
	a++;
	b++;
}
if(check == 0){
	printf("The two strings are same\n");
}
else{
	printf("The two strings are different\n");
}
return 0;
}
