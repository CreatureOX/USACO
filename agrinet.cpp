 /*
ID: keepagr1
LANG: C++
PROG: agrinet
*/
#include<iostream>
#include<cstring>
#include<stdio.h>
#define INF 1 << 30
#define N 586
using namespace std;

int n;
int d[N];
int a[N][N];
bool v[N] = {0};

int prim(){
    int ans = 0, min = INF, k = 0;
    v[0] = 1;
    for(int num = 1; num < n; num++, ans+= min, min = INF, v[k] = 1){
        for(int y = 0; y < n; y++){
            if(!v[y] && d[y] > a[y][k]){
                d[y] = a[y][k];                
            }
        }
        for(int y = 0; y < n; y++){
        if(!v[y] && d[y] < min){
            min = d[k=y];
            } 
        } 
    }
    return ans;
}

void init(){
    memset(v, 0, sizeof(v));
    memset(a, 0, sizeof(a));
    memset(d, 0x3f3f3f, sizeof(d));
}

int main(){
    FILE *fin = fopen("agrinet.in","r");
    FILE *fout = fopen("agrinet.out","w");
    while(~fscanf(fin, "%d", &n)){
        init();
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) fscanf(fin, "%d", &a[i][j]);
        fprintf(fout,"%d\n", prim());
    }
    return 0;
}
