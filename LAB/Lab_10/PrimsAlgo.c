#include <stdio.h>
#define MAX 100
int q[MAX], s[MAX], d[MAX];
int front = -1;
int rear = -1;
int count = 0;
int min_cost = 0;
void check (int d1, int d2, int d3) {
    int i,j;
    for(i = 0; i <= rear; ++i) {
        if(d1 >= q[i]) {
            for(j = rear+1; j > i; j--) {
                q[j] = q[j-1];
                s[j] = s[j-1];
                d[j] = d[j-1];
            }
            q[i] = d1;
            s[i] = d2;
            d[i] = d3;
            return;
        }
    }
    q[i] = d1;
    s[i] = d2;
    d[i] = d3;
}
void enqueue (int d1,int d2,int d3) {
    if(rear >= MAX-1) {
        return;
    }
    if((front == -1) && (rear == -1)) {
        front++;
        rear++;
        q[rear] = d1;
        s[rear] = d2;
        d[rear] = d3;
        return;
    }
    else{
        check(d1,d2,d3);
    }
    rear++;
}
int dequeue (int a[][MAX]) {
    int min = q[front], k = rear, e, i;
    e = d[rear];
    printf("Source: %d\t Destination: %d\t Cost: %d\n",s[k],d[k],q[k]);
    min_cost += q[k];
    a[d[k]][s[k]] = 0;
    count++;
    rear--;
    return e;
}
void prim(int a[][MAX],int n, int b){
    int i, dest;
    if(count == n - 1){
        return;
    }
    for(i = 0; i < n; ++i) {
        if(a[b][i] > 0) {
            enqueue(a[b][i],b,i);
        }
    }
    dest = dequeue(a);
    prim(a,n,dest);
}
int main() {
    int i,j,n;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);

    int graph[n][n];
    printf("Enter the cost adjacency Matrix\n");
    for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		    scanf("%d",&graph[i][j]);
	    }
    }
    printf("The Cost Adjacency Matrix is \n");
    for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		    printf("%d  ",graph[i][j]);
	    }
	    printf("\n");
    }
    printf("\nPrims Algorithm\n\n");
    prim(graph,n,0);
    printf("\nMinimum Cost of the Spanning Tree = %d \n",min_cost);
    return 0;
}
