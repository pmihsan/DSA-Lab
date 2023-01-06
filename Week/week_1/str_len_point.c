#include<stdio.h>
int main() 
{
char str[20], *p;
int i = 0;
printf("Enter your string\n");
gets(str);
p = str;
while (*p != '\0') 
{
         i++;
         p++;
}
printf("Length of String using pointer is %d\n", i);
return 0;
}
