#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph
{
    int numVertices;
    int* visited;
    struct node** adjLists; 
};

struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int);
void printGraph(struct Graph*);
void DFS(struct Graph*, int);

int main()
{
    int n;
    int startVertex;
    printf("Enter how many vertices\n");
    scanf("%d",&n);
    struct Graph* graph = createGraph(n);
    int maxEdge = n*(n-1);
    int origin,destin;
    for (int count = 1; count <= maxEdge; count++)
    {
      printf("Enter edge %d(-1 -1 to quit )\n",count);
      scanf("%d %d",&origin,&destin);
      if((origin == -1) && (destin == -1))
         break;
      if(origin>=n || destin>=n || origin<0 || destin<0)
      {
         printf("Invalid edge!\n");
         count--;
      }
      else
      {
         addEdge(graph,origin,destin);
      }
    } 
    printGraph(graph);
    printf("Enter the Starting Vertex\n");
    scanf("%d",&startVertex);
    printf("DFS Traversal\n");
    DFS(graph, startVertex);
    return 0;
}

void DFS(struct Graph* graph, int vertex) {
        struct node* ptr = graph->adjLists[vertex];
        graph->visited[vertex] = 1;
        printf("%d  ", vertex);
        while(ptr!=NULL) {
            int adj_vertex = ptr->vertex;
            if(graph->visited[adj_vertex] == 0) {
                DFS(graph, adj_vertex);
            }
            ptr = ptr->next;
        }       
}

 
struct node* createNode(int v)
{
    struct node* new_node = malloc(sizeof(struct node));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
 
void addEdge(struct Graph* graph, int source, int destination)
{
    // Add edge from src to dest
    struct node* newNode = createNode(destination);
    newNode->next = graph->adjLists[source];
    graph->adjLists[source] = newNode;
    // Add edge from destination to source
    newNode = createNode(source);
    newNode->next = graph->adjLists[destination];
    graph->adjLists[destination] = newNode;
}
 
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* ptr = graph->adjLists[v];
        printf("Adjacency list of vertex %d\n", v);
        while (ptr)
        {
            printf("%d -> ", ptr->vertex);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
