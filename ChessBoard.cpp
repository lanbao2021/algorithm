// ChessBoard.cpp
// Created by 蓝同学 on 2022/1/19.
// 棋盘问题

#include<stdio.h>
#define MAX 1025

int k;
int x,y;

int board[MAX][MAX];
int tile = 1;

void Chess_Board(int tr, int tc, int dr, int dc, int size){
    if(size==1)
        return;
    int t=tile++;
    int s=size/2;

    // left up
    if(dr<tr+s && dc<tc+s)
        Chess_Board(tr, tc, dr, dc, s);
    else{
        board[tr+s-1][tc+s-1]=t;
        Chess_Board(tr,tc, tr+s-1, tc+s-1, s);
    }

    // right up
    if(dr<tr+s && dc>=tc+s)
        Chess_Board(tr, tc+s, dr, dc, s);
    else{
        board[tr+s-1][tc+s]=t;
        Chess_Board(tr, tc+s, tr+s-1, tc+s, s);
    }

    // left down
    if(dr>=tr+s && dc<tc+s)
        Chess_Board(tr+s, tc, dr, dc, s);
    else{
        board[tr+s][tc+s-1] = t;
        Chess_Board(tr+s, tc, tr+s, tc+s-1, s);
    }

    // right down
    if(dr>=tr+s && dc>=tc+s)
        Chess_Board(tr+s, tc+s, dr, dc, s);
    else{
        board[tr+s][tc+s]=t;
        Chess_Board(tr+s, tc+s, tr+s, tc+s, s);
    }

}

int main(){
    k=3;
    x=1;
    y=2;
    int size=1<<k;
    Chess_Board(0,0,x,y,size);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++)
            printf("%4d", board[i][j]);
        printf("\n");
    }
    return 0;
}

