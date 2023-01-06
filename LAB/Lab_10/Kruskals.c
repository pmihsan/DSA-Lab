#include<stdio.h>
#include<stdlib.h>
#define INF 999

int i,j,k;
int u,v,n,a,b;
int no_of_edge = 1;
int min, min_cost = 0;
int costMat[9][9],parent[9];

int find(int a){
	while(parent[a]){
		a = parent[a];
	}
	return a;
}

int uni_on(int a, int b){
	if(a != b){
		parent[b] = a;
		return 1;
	}
	return 0;
}

int main(){
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the cost adjacency Matrix\n");
	for(i = 0;i<n;i++){
		for(j = 0;j<n;j++){
			scanf("%d",&costMat[i][j]);
			if(costMat[i][j] == 0){
				costMat[i][j] = INF;
			}
		}
	}	
	printf("\nKruskals Algorithm\n");
	printf("\nThe Edges of the minimum cost spanning tree are\n");
	while(no_of_edge < n){
		for(i = 0,min = INF;i < n;i++){
			for(j = 0;j < n;j++){
				if(costMat[i][j] < min){
					min = costMat[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
	u = find(u);
	v = find(v);
	if(uni_on(u,v)){
		printf("VERTEX %d - EDGE(%d, %d) = COST %d\n",no_of_edge++,a,b,min);
		min_cost += min;
	}
	costMat[a][b] = costMat[b][a] = INF;
	}
	printf("\nMinimum Cost of the Spanning Tree is %d\n",min_cost);
	return 0;
}
