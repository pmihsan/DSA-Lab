#include<stdio.h>
void cube();
void cuboid();
void cylinder();
int main()
{
int choice;
printf("Enter which shape you want to find volume\n");
printf("1.Cube\n2.Cuboid\n3.Cylinder\nEnter your choice\n");
scanf("%d",&choice);
switch(choice){
	case 1:{
	      cube();
	      break;
      }
	case 2:{
	      cuboid();
	      break;
      }
	case 3:{
	     cylinder();
	     break;
     }
}
return 0;
}
void cube(){
int a;
printf("Enter the side(length) of cube\n");
scanf("%d",&a);
printf("Volume of the cube is %d\n\n",a*a*a);
main();
}

void cuboid(){
int l,b,h;
printf("Enter length, breadth and height of cuboid\n");
scanf("%d %d %d",&l,&b,&h);
int area;
area = (l*b*h);
printf("Volume of the cuboid is %d\n\n",area);
main();
}
void cylinder(){
int r,h;
printf("Enter the radius and height of the cylinder\n");
scanf("%d %d",&r,&h);
int area = 3.14 * (r * r) * h;
printf("Volume of the cylinder is %d\n",area);
}
