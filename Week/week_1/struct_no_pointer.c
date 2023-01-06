#include<stdio.h>
struct student{
	int roll;
	float cgpa;
	char name[20];
}s[10];
void print_details(struct student s[],int n);
int main()
{
int i,n,r;
printf("Enter how many student details you want to give\n");
scanf("%d",&n);
for(i=0;i<n;i++){
	printf("Enter the %d student name\n",i+1);
	scanf("%s",s[i].name);
	printf("Enter the %d student roll number\n",i+1);
	scanf("%d",&s[i].roll);
	printf("Enter the %d student cgpa\n",i+1);
	scanf("%f",&s[i].cgpa);
}	
	printf("Do you want to print the details\nThen press 1\n");
	scanf("%d",&r);
	if(r == 1){
		print_details(s, n);
	}
return 0;
}
void print_details(struct student s[],int n){
int i;
printf("The student details are\n");
for(i=0;i<n;i++){
	printf("Student %d name: %s\n",i+1,s[i].name);
	printf("Student %d roll number: %d\n",i+1,s[i].roll);
	printf("Student %d cgpa: %f\n",i+1,s[i].cgpa);

}
}
