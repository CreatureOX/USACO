/*
ID: keepagr1
LANG: C++
PROG: hamming
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
bool vis[1024],use[10];
int ans[1024],n,b,d,cnt;
 
void dfs(int t,int x){
    vis[t]=true;
    if(x<=0) return ;
    for(int i=0;i<b;i++){
        if(!use[i]){
            use[i]=true;
            dfs(t^(1<<i),x-1);
            use[i]=false;
        }
    }
}
 
int main(){
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    scanf("%d%d%d",&n,&b,&d);
 
    for(int i=0;i<(1<<b);i++){
        if(vis[i]==false){
            ans[cnt++]=i;
            memset(use,0,sizeof(use));
            dfs(i,d-1);
            if(cnt==n) break;
        }
    }
 
    for(int i=0;i<n;i++){
        printf("%d",ans[i]);
        if((i+1)%10==0) putchar(10);
        else if(i+1!=n) putchar(32);
    }
    if(n%10) putchar(10);
    return 0;
}
