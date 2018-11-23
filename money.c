 /*
ID: keepagr1
LANG: C
PROG: money
*/
#include<stdio.h>
#define MAX 10010
#define ll long long int
int V,N;
int coins[30];
ll dp[30][MAX];
int main(){
    FILE *fin = fopen("money.in", "r");
    FILE *fout = fopen("money.out", "w");
    int i,j;
    fscanf(fin,"%d%d", &V,&N);
    for(i=1;i<=V;i++){
        fscanf(fin,"%d",&coins[i]);
        dp[i][coins[i]] = 1;
    }
    for(i=1;i<=V;i++)
        for(j=1;j<=N;j++){
            if(j>coins[i]){
                dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i][j] + dp[i-1][j];
            }
        }
    fprintf(fout,"%lld\n",dp[V][N]);
    return 0;
}