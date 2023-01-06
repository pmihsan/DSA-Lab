#include<stdio.h>
void square();
void triangle();
void circle();
int main()
{
int choice;
printf("Enter which shape you want to find area\n");
printf("1.Square\n2.triangle\n3.Circle\nEnter your choice\n");
scanf("%d",&choice);
switch(choice){
	case 1:{
	      square();
	      break;
      }
	case 2:{
	      triangle();
	      break;
      }
	case 3:{
	     circle();
	     break;
     }
}
return 0;
}
void square(){
int a;
printf("Enter the side(length) of square\n");
scanf("%d",&a);
printf("Area of the square is %d\n\n",a*a);
main();
}

void triangle(){
int b,h;
printf("Enter base and height of a triangle\n");
scanf("%d %d",&b,&h);
int area;
area = (b*h)/2;
printf("Area of the triangle is %d\n\n",area);
main();
}
void circle(){
int r;
printf("Enter the radius of the circle\n");
scanf("%d",&r);
int area = 3.14 * (r * r);
printf("Area of the circle is %d\n",area);
}
