/*
ID: keepagr1
LANG: C++
PROG: nocows
*/
#include<cstdio>
using namespace std;
const int maxn = 205;
const int mod = 9901;
int n,k;
int dp[maxn][maxn];
int main(){
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
    scanf("%d%d",&n,&k);
    /*
    dp[i][j]代表总结点数为i的，高度不超过j的树的种类
    dp[i][j] += dp[k][j] * dp[i - k - 1][j];
    
    注意取余的情况
    结果为 dp[n][k] - dp[n][k - 1]
    */
    for(int i = 1; i <= k; i++) dp[1][i] = 1;
    for(int d = 1; d <= k; d++)
        for(int i = 1; i <= n; i++)
            for(int k = 1; k < i; k++){
                dp[i][d] += dp[k][d - 1] * dp[i - k - 1][d - 1];
                dp[i][d] %= mod;
            }
    int ans = (dp[n][k] - dp[n][k - 1] + mod) % mod;
    printf("%d\n",ans);
    return 0;
}
