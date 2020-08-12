#include<stdio.h>
#include<iostream>
void f(int n,int *p){
    int f1,f2;
    if(n==1||n==2){
        *p = n+1;
    }
    else{
        f(n-1,&f1);
        f(n-2,&f2);
        *p = f1*f2+1;
    }
}
int main(){
    int n;
    f(5,&n);
    printf("%d",n);
    system("pause");
}