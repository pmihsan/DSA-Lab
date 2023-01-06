#include<stdio.h>
#define N 7
int arr[N];
int res[N];

void printSubsets(){
    for(int i=0;i<N;i++){
        if(res[i] == 1){
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
}

void SumOfSubsets(int s, int sum, int maxSum){
    if(s == N){
        return;
    }
    res[s] = 1;
    sum += arr[s]; 
    if(sum == maxSum){
        printSubsets();
    }
    else if(sum + arr[s] <= maxSum){
        SumOfSubsets(s+1,sum,maxSum);
    }
    res[s] = 0;
    sum -= arr[s];
    if(sum + arr[s] <= maxSum){
        SumOfSubsets(s+1,sum,maxSum);
    }
}

void main(){
    int sum = 0,start = 0;
    int maxSum;
    printf("Enter the array of %d elements\n",N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<N;i++){
        res[i] = 0;
    }
    printf("Enter the maxSum of the subset\n");
    scanf("%d",&maxSum);
    printf("SUBSETS\n");
    SumOfSubsets(start,sum,maxSum);
}
