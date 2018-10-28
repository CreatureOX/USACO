/*
ID: keepagr1
PROG: runround
LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
typedef int bool;
#define true 1
#define false 0
#define MAX 10

int num[MAX];
int len;
int M;

bool isRunround(){
    int check[MAX] = {0};
    int i = len - 1;
    i = i - num[i] > 0?(i - num[i]) % len : len + (i - num[i]) % len;
    while (check[i] == 0) {
        check[i] = 1;
        i = i - num[i] > 0 ? (i - num[i]) % len : len + (i - num[i]) % len;
    }
    for (i = 0; i < len; i++)
        if (check[i] == 0)
            return false;
    return true;
}
bool isUnique(){
    int check[MAX] = {0};
    int i;
    for(i=0;i<len;i++){
        if(check[num[i]] == 1 || num[i]==0)
            return false;
        check[num[i]] = 1;
    }
    return true;
}
void get(int n){
    int i,m;
    for(i=0,m=n;m!=0;i++,m/=10)
        num[i] = m%10;
    len = i;
}
int main(){
    FILE *fin = fopen("runround.in","r");
    FILE *fout = fopen("runround.out","w");
    fscanf(fin, "%d", &M);
    int i;
    for(i=M+1;;i++){
        get(i);
        if(isUnique() && isRunround()){
            break;
        }
    }
    fprintf(fout, "%d\n", i);
    return 0;
}