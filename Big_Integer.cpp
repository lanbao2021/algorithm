// Big_Integer.cpp
// Created by 蓝同学 on 2022/1/19.
// 求解大整数乘法问题

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define MAXN 20 // 二进制整数最多的位数
int num = 1; // 计算递归次数

void Left(int A[], int B[], int n){ // 取A的左边（高位到低位）的n/2位放入B中
    int i;
    for(i=0; i<MAXN; i++)
        B[i]=0;
    for(i=n/2; i<=n; i++)
        B[i-n/2]=A[i];
//    cout << "调用Left函数得：";
//    for(i=0; i<MAXN; i++)
//        cout << B[i];
//    cout << endl;
}

void Right(int A[], int B[], int n){
    int i;
    for(i=0; i<MAXN; i++)
        B[i]=0;
    for(i=0; i<n/2; i++)
        B[i] = A[i];
//    cout << "调用Right函数得：";
//    for(i=0; i<MAXN; i++)
//        cout << B[i];
//    cout << endl;
}

long Trans2to10(int A[]){
    int i;
    long s=A[0], x=1;
    for(i=1; i<MAXN; i++){
        x = 2*x;
        s += A[i] * x;
    }
//    cout << "调用Trans2to10函数得：";
//    cout << s << endl;
    return s;
}

void Trans10to2(int x, int A[]){
    int i, j=0;
    while(x>0){
        A[j] = x%2;
        j++;
        x=x/2;
    }
    for(i=j; i<MAXN; i++)
        A[i]=0;
//    cout << "调用Trans10to2函数得：";
//    for(i=0; i<MAXN; i++)
//        cout << A[i];
//    cout << endl;

}

void disp(int A[]){ // 从高位到低位输出二进制数A
    cout << "调用disp函数得： ";
    int i;
    for(i=MAXN-1; i>=0; i--)
        cout << A[i];
    cout << endl;
}

void MULT(int X[], int Y[], int Z[], int n, int cnt=num, int ceng=1){

    int i;
    long e, e1, e2, e3, e4;
    int A[MAXN], B[MAXN], C[MAXN], D[MAXN];
    int m1[MAXN], m2[MAXN], m3[MAXN], m4[MAXN];

    for(i=0; i<MAXN; i++) // Z初始化为0
        Z[i]=0;

    cout << "MULT函数的第" << num << "次调用开始(第" << ceng++ << "层)" <<endl;
//    cout << "形参X[]:";
//    for(int k=0; k<MAXN; k++)
//        cout << X[k];
//    cout << endl;
//    cout << "形参Y[]:";
//    for(int k=0; k<MAXN; k++)
//        cout << Y[k];
//    cout << endl;
//    cout << "形参Z[]:";
//    for(int k=0; k<MAXN; k++)
//        cout << Z[k];
//    cout << endl;
    cout << "形参n：" << n << endl;

    if(n==1){
        cout << "MULT函数的第" << cnt << "次调用结束(第" << ceng++ << "层)\n" <<endl;
        if(X[0]==1 && Y[0]==1)
            Z[0]=1;
        else
            Z[0]=0;
    }
    else{

        Left(X, A, n);
        Right(X, B, n);
        Left(Y, C, n);
        Right(Y, D, n);
        MULT(A, C, m1, n/2, ++num, ceng);
        MULT(A, D, m2, n/2, ++num, ceng);
        MULT(B, C, m3, n/2, ++num, ceng);
        MULT(B, D, m4, n/2, ++num, ceng);
        e1 = Trans2to10(m1);
        e2 = Trans2to10(m2);
        e3 = Trans2to10(m3);
        e4 = Trans2to10(m4);
        e = e1*(int)pow(2, n) + (e2+e3)*(int)pow(2, n/2) + e4;
        Trans10to2(e, Z);
        cout << "e1=" << e1 << ','
        << "e2=" << e2 << ','
        << "e3=" << e3 << ','
        << "e4=" << e4 << endl;

    }


}

void trans(char a[], int n, int A[]){
    int i;
    for(i=0; i<n; i++)
        A[i] = int(a[n-1-i] - '0');
    for(i = n; i<MAXN; i++)
        A[i]=0;
//    cout << "trans函数调用结果：";
//    for(i=0; i<MAXN; i++)
//        cout << A[i];
//    cout << endl;
}

int main(){
    long e;
    char a[]="10101100";
    char b[]="10010011";
    int X[MAXN], Y[MAXN], Z[MAXN];
    int n=8;
    trans(a, n, X);
    trans(b, n, Y);
    disp(X);
    disp(Y);
    cout << "Z=X*Y" << endl;
    MULT(X, Y, Z, n);
    disp(Z);
    e = Trans2to10(Z);
    cout << "Z对应的十进制数：" << e << endl;
    cout << "验证正确性：" << endl;
    long x, y, z;
    x = Trans2to10(X);
    y = Trans2to10(Y);
    cout << "X对应的十进制数：" << X << endl;
    cout << "Y对应的十进制数：" << Y << endl;
    cout << "z=x*y" << endl;
    z = x*y;
    cout << "求解结果z：" << z << endl;
    return 0;
}

