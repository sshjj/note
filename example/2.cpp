#include<stdio.h>
#include<iostream>
int f(char s[]){
    int n = 0;
    while(*s<='9' && *s>='0'){
        n = 10*n+*s-'0';
        s++;
    }
    return n;
}
int main(){
    char s[10] = {'6','1','7','*','4','*','-','+','/'};
    printf("%d\n",f(s));
    system("pause");
    return 0;
}