#include<stdio.h>
int main(){
int mat1[2][2],mat2[2][2],res[2][2];
int i,j,k;
int p1,p2,p3,p4,p5,p6,p7;
printf("Strassen Matrix Multiplication of two matrices having order 2\n");
printf("Enter the Elements of the first matrix\n");
for(i =0;i<2;i++){
	for(j =0;j<2;j++){
		scanf("%d",&mat1[i][j]);
	}
}
printf("Enter the Elements of the second matrix\n");
for(i =0;i<2;i++){
        for(j =0;j<2;j++){
		scanf("%d",&mat2[i][j]);
	}
}
printf("First Matrix\n");
for(i =0;i<2;i++){
        for(j =0;j<2;j++){
		printf("%d  ",mat1[i][j]);
	}
	printf("\n");
}
printf("Second Matrix\n");
for(i =0;i<2;i++){
        for(j =0;j<2;j++){
		printf("%d  ",mat2[i][j]);
	}
	printf("\n");
}
//Strassen Matrix Multiplication using 2X2 Matrix
p1 = mat1[0][0] * (mat2[0][1] - mat2[1][1]);
p2 = mat2[1][1] * (mat1[0][0] + mat1[0][1]);
p3 = mat2[0][0] * (mat1[1][0] + mat1[1][1]);
p4 = mat1[1][1] * (mat2[1][0] - mat2[0][0]);
p5 = (mat1[0][0] + mat1[1][1]) * (mat2[0][0] + mat2[1][1]);
p6 = (mat1[0][1] - mat1[1][1]) * (mat2[1][0] + mat2[1][1]);
p7 = (mat1[0][0] - mat1[1][0]) * (mat2[0][0] + mat2[0][1]);

res[0][0] = p4 + p5 + p6 - p2;
res[0][1] = p1 + p2;
res[1][0] = p3 + p4;
res[1][1] = p1 + p5 - p3 - p7;

//printf("%d %d %d %d\n",res[0][0],res[0][1],res[1][0],res[1][1]);

printf("Multiplied Matrix\n");
for(i =0;i<2;i++){
        for(j =0;j<2;j++){
		printf("%d  ",res[i][j]);
	}
	printf("\n");
}
}
