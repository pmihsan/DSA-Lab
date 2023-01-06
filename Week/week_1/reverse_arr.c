#include<stdio.h>
int main()
{
int arr[20];
int n,i;
printf("Enter how many elements are you going to give\n");
scanf("%d",&n);
printf("Enter your %d elements\n",n);
for(i=0;i<n;i++){
	scanf("%d",&(arr[i]));
}
printf("Your reversed array is\n");
for(i = n-1;i >= 0;i--){
	printf("%d\n",arr[i]);
}
return 0;
}
