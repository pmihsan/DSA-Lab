#include<stdio.h>
int main(){
int a[5][5],b[5][5],c[5][5];
int i,j,k;
int row,col;
printf("Enter the number of rows and columns\n");
scanf("%d %d",&row,&col);
printf("Enter the first matrix\n");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
		scanf("%d",(*(a+i)+j));	}
}
printf("Enter your second matrix\n");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
		scanf("%d",(*(b+i)+j));	}
}
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
		(*(*(c+i)+j)) = (*(*(a+i)+j)) - (*(*(b+i)+j));
	}
}
printf("After Substracting ie(first - second) the matrix is\n");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
		printf("%d\t",(*(*(c+i)+j)));
	}
	printf("\n");
}
return 0;
}
