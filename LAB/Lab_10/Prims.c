#include<stdio.h>
#include<stdlib.h>
#define MAX 9999
struct node {
	int data;
	int priority;
	struct node *next;
};
struct node *insert(struct node *start, int val, int pri) {
	struct node *ptr, *p;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->priority = pri;
	if(start==NULL || pri < start->priority ) {
		ptr->next = start;
		start = ptr;
	}
	else {
		p = start;
		while(p->next != NULL && p->next->priority <= pri)
		p = p->next;
		ptr->next = p->next;
		p->next = ptr;
	}
	return start;
}
int del(struct node **start) {
	struct node *ptr;
	if(start == NULL) {
		printf("\n UNDERFLOW");
		return -1;
	}
	else {
		ptr = *start;
		int ret = ptr->data;
		*start = (*start)->next;
		free(ptr);
		return ret;
	}
}
void changePriority(struct node *start, int vertex, int key) {
	struct node *p = start;
	while(p!=NULL) {
		if(p->data == vertex) {
			p->priority = key;
			return;
		}
		p=p->next;
	}
}
int main() {
	printf("Number of vertices:");
	int v;
	scanf("%d", &v);
	int graph[v][v];
	for(int i=0; i<v; ++i) {
		for(int j=0; j<v; ++j) {
			graph[i][j] = MAX;
		}
	}
	printf("Enter the number of edges:");
	int e;
	scanf("%d", &e);
	for(int i=0; i<e; ++i) {
		int v1, v2, cost;
		printf("Enter the vertices v1, v2 and their cost:");
		scanf("%d %d %d", &v1, &v2, &cost);
		graph[v1][v2] = cost;
		graph[v2][v1] = cost;
	}
	int key[v], curr, adj, parent[v];
	struct node *start = NULL;
	for(int i=0; i<v; ++i) {
		key[i] = MAX;
		parent[i] = -1;
	}
	key[0] = 0;
	for(int i=0; i<v; ++i) {
		start = insert(start, i, key[i]);
	}
	printf("\nThe minimum spanning tree:\n");
	while(start!=NULL) {
		int vertex = del(&start);
		for(int i=0; i<v; ++i) {
			if(graph[vertex][i] != MAX) {
				if(graph[vertex][i]<key[i]) {
					printf("%d-%d Cost:%d\n", vertex, i, graph[vertex][i]);
					key[i] = graph[vertex][i];
					changePriority(start, i, graph[vertex][i]);	
				}
			}
		}
	}
}
