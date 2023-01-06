#include<stdio.h>
int main()
{
int i;
char str[20];
printf("Enter your string\n");
scanf("%s",str);
for(i = 0;str[i] != '\0';++i)
	;
printf("Length of the string is %d\n",i);
return 0;
}
