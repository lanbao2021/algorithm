// queen.cpp
// Created by 蓝同学 on 2022/1/18.
// n皇后问题

#include<stdio.h>
#include<stdlib.h>
#define N 20
int q[N];
int count=0;

void dispasolution(int n){
    printf("第%d个解：", ++count);
    for(int i=1; i<=n; i++)
        printf("(%d, %d)", i, q[i]);
    printf("\n");
}

bool place(int i, int j){
    if(i==1)
        return true;
    int k=1;
    while(k<i){
        if((q[k]==j) || (abs(q[k]-j)==abs(i-k)))
            return false;
        k++;
    }
    return true;
}

void Queen(int i, int n){
    if(i>n)
        dispasolution(n);
    else{
        for(int j=1; j<=n; j++)
            if(place(i,j)){
                q[i]=j;
                Queen(i+1, n);
            }
    }
}

int main(){
    int n;
    n=6;
    Queen(1,6);
    return 0;
}

