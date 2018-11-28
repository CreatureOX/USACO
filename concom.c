/*
ID: keepagr1
LANG: C
PROG: concom
*/
#include<stdio.h>
#include<stdlib.h>
int m,n = 0;
int share[110][110];
int con[110][110];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    FILE *fin = fopen("concom.in","r");
    FILE *fout = fopen("concom.out","w");
    memset(share, 0, sizeof(share));
    memset(con, 0, sizeof(con));
    fscanf(fin, "%d", &m);
    int A,B,x;
    for(int i=1;i<=m;i++){
        fscanf(fin, "%d%d%d", &A,&B,&x);
        n = max(n, max(A,B));
        share[A][B] = x;
        if(x > 50){
            con[A][B] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        con[i][i] = 1;
    }
    while(1){
        int flag = 1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(!con[i][j]){
                    int total = 0;
                    for(int k=1;k<=n;k++){
                        if(con[i][k]){
                            total += share[k][j];
                        }
                    }
                    if(total > 50 && !con[i][j]){
                        flag = 0;
                        con[i][j] = 1;
                    }
                }
            }
            if(flag){
                break;
            }
    }
    for(int h=1;h<=n;h++)
        for(int s=1;s<=n;s++){
            if(con[h][s] && (h!=s)){
                fprintf(fout, "%d %d\n", h,s);
            }
        } 
    return 0;
}