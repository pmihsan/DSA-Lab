#include<stdio.h>
#define NODE 3
#define INF 9999
//Cost matrix of the graph
int costMat[NODE][NODE] = {
   {0, 4, 11},
   {6, 0, 2},
   {3, INF, 0}
};
void floydWarshal(){
    //defind to store shortest distance from any node to any node
   int cost[NODE][NODE]; 
   for(int i = 0; i<NODE; i++){
      for(int j = 0; j<NODE; j++){
          //copy costMatrix to new matrix
         cost[i][j] = costMat[i][j];
      }
   }
         for(int k = 0; k<NODE; k++){
            for(int i = 0; i<NODE; i++){
               for(int j = 0; j<NODE; j++){
                   //find minimum distance
                  if(cost[i][k]+cost[k][j] < cost[i][j]){
                     cost[i][j] = cost[i][k]+cost[k][j];
                  }
               }
            }
         }
   printf("The All Pair Shortest Path Matrix is \n");
   for(int i = 0; i<NODE; i++){
      for(int j = 0; j<NODE; j++){
         printf("%d  ",cost[i][j]);
      }
      printf("\n");
   }
}
int main(){
   printf("The Cost Matrix of the given weighted (directed) graph\n");
   for(int i = 0; i<NODE; i++){
      for(int j = 0; j<NODE; j++){
         printf("%d  ",costMat[i][j]);
      }
      printf("\n");
   }
   floydWarshal();
   return 0;
}

