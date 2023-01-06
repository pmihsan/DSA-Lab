#include<stdio.h>
#include<stdbool.h>
#define N 4

void display(int board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]){
                printf(" Q ");
            }
            else{
            printf(" X ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printBoard(int board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
                printf(" %d ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[N][N], int row, int col){
    for(int i=0;i<row;i++){
        if(board[i][col]){
            return 0;
        }
    }
    int maxLeft = row < col ? row : col;
    for(int i=1;i<= maxLeft;i++){
        if(board[row-i][col-i]){
            return 0;
        }
    }
    int maxRight = row < N-col-1 ? row : N-col-1;
    for(int i=1;i<= maxRight;i++){
        if(board[row-i][col+i]){
            return 0;
        }
    } 
    return 1;
}

int Queens(int board[N][N], int row){
    if(row == N){
        printBoard(board);
        return 1;
    }
    int count = 0;
    for(int col = 0;col < N;col++){
        if(isSafe(board,row,col)){
            board[row][col] = true;
            count += Queens(board,row+1);
            board[row][col] = false;
        }
    }
    return count;
}

void main(){
    int board[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j] = 0;
        }
    }
    int ans = Queens(board,0);
    printf("No of ways to place the %d-Queens in %d X %d is %d\n",N,N,N,ans);
}
