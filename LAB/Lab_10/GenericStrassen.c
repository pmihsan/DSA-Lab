#include<stdio.h>
#define MAX 10

void Strassen(int mat1[MAX][MAX],int mat2[MAX][MAX], int n);
int main(){
int mat1[MAX][MAX],mat2[MAX][MAX],res[MAX][MAX];
int i,j,k;
int n;
int p1,p2,p3,p4,p5,p6,p7;
printf("Strassen Matrix Multiplication of two matrices having order n\n");
printf("Enter the order of the matrix\n");
scanf("%d",&n);
printf("Enter the Elements of the first matrix\n");
for(i =0;i<n;i++){
	for(j =0;j<n;j++){
		scanf("%d",&mat1[i][j]);
	}
}
printf("Enter the Elements of the second matrix\n");
for(i =0;i<n;i++){
        for(j =0;j<n;j++){
		scanf("%d",&mat2[i][j]);
	}
}
printf("First Matrix\n");
for(i =0;i<n;i++){
        for(j =0;j<n;j++){
		printf("%d  ",mat1[i][j]);
	}
	printf("\n");
}
printf("Second Matrix\n");
for(i =0;i<n;i++){
        for(j =0;j<n;j++){
		printf("%d  ",mat2[i][j]);
	}
	printf("\n");
}
Strassen(mat1,mat2,n);
}
void Strassen(int mat1[][MAX],int mat2[][MAX], int n){

}
