#include<stdio.h>
#include<string.h>
#define N 20

int Max(int a,int b){
    return a>b ? a : b;
}

int LCS_DP(char x[], char y[], int m, int n){
    
    int LCS[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0 || j == 0){
                LCS[i][j] = 0;
            }
            else if(x[i-1] == y[j-1]){
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else{
                LCS[i][j] = Max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }

    int ind = LCS[m][n];
    char lcs[ind+1];
    lcs[ind] = '\0';
    int i = m, j = n;
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            lcs[ind - 1] = x[i-1];
            i--;
            j--;
            ind--;
        }
        else if(LCS[i-1][j] > LCS[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    printf("Longest Common Subsequence - %s\n",lcs);
    
    return LCS[m][n];
}

void main(){
    char x[N],y[N];
    printf("Enter the two strings\n");
    scanf("%s",x);
    scanf("%s",y);
    int m = strlen(x);
    int n = strlen(y);
    int ans = LCS_DP(x,y,m,n);
    printf("The length of longest common subsequence is %d\n",ans);
}
