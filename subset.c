/*
ID: keepagr1
PROG: subset
LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n, sum, ans;
long long dp[100][1000];
int main(){
	FILE *fin = fopen("subset.in","r");
	FILE *fout = fopen("subset.out","w");
    fscanf(fin, "%d", &n);
    sum = n*(n+1)/2;
    int i,j;
    dp[0][0] = 1;
    if(sum%2 == 0){
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum/2;j++)
                dp[i][j]+=dp[i-1][j]+(j>=i?dp[i-1][j-i]:0);
        }
    }
    fprintf(fout, "%lld\n", dp[n][sum/2]/2);
    return 0;
}
