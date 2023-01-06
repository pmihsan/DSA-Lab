#include<stdio.h>
#include<stdlib.h>
 
#define MAX 100  

int n;    
 //adjacency matrix, where adj[i][j] = 1, denotes there is an  edge from i to j
int adj[MAX][MAX]; 
 //visited[i] can be 0 / 1, 0 : it has not yet printed, 1 : it has been printed 
int visited[MAX];   
void create_graph();
void BFS();
 
int queue[MAX], front = -1,rear = -1;
void push(int vertex);
int pop();
int isEmpty();
 
int main()
{
   create_graph();
   BFS();
   return 0;
}

void BFS()
{
    int v;
   for(v=0; v<n; v++)
      visited[v] = 0;
   printf("Enter Start Vertex for BFS: \n");
   scanf("%d", &v);
   printf("BFS Traversal\n"); 
   int i;  
   push(v);
   while(!isEmpty())
   {  
      v = pop( );
      //if it has already been visited by some other neighbouring vertex, it should not be printed again.
       if(visited[v])    
           continue;   
      printf("%d ",v);
      visited[v] = 1;
      for(i=0; i<n; i++)
      {
         if(adj[v][i] == 1 && visited[i] == 0)
         {
            push(i);
         }
      }
   }
   printf("\n");
}
 
void push(int vertex)
{
   if(rear == MAX-1)
      printf("Queue Overflow\n");
   else
   {
      if(front == -1)
         front = 0;
      rear = rear+1;
      queue[rear] = vertex ;
   }
}
 
int isEmpty()
{
   if(front == -1 || front > rear)
      return 1;
   else
      return 0;
}
 
int pop()
{
   int delete_item;
   if(front == -1 || front > rear)
   {
      printf("Queue Underflow\n");
      exit(1);
   }
   delete_item = queue[front];
   front = front+1;
   return delete_item;
}
 
void create_graph()
{
   int count,max_edge,origin,destin;
   printf("Enter number of vertices\n");
   scanf("%d",&n);
   //assuming each vertex has an edge with remaining (n-1) vertices
   max_edge = n*(n-1);  
   for(count=1; count<=max_edge; count++)
   {
      printf("Enter edge %d( -1 -1 to quit )\n",count);
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
        // assuming it is a bi-directional graph, we are pushing the reverse edges too.
         adj[origin][destin] = 1;
         adj[destin][origin] = 1;
      }
   }
}
