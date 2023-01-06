#include<stdio.h>
#include<stdlib.h>
struct student{
	int roll;
	float cgpa;
	char name[20];
}*s;
void print_details(struct student *s);
int main()
{
int r;
printf("Enter the student details you want to give\n");
        s = (struct student *)malloc(sizeof(struct student *));
	printf("Enter the student name\n");
	scanf("%s",s->name);
	printf("Enter the student roll number\n");
	scanf("%d",&s->roll);
	printf("Enter the student cgpa\n");
	scanf("%f",&s->cgpa);

	printf("Do you want to print the details\nThen press 1\n");
	scanf("%d",&r);
	if(r == 1){
		print_details(s);
	}
return 0;
}
void print_details(struct student *s){
printf("The student details are\n");
	printf("Student name: %s\n",s->name);
	printf("Student roll number: %d\n",s->roll);
	printf("Student cgpa: %f\n",s->cgpa);
}
