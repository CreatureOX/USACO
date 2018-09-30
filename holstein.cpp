/*
ID: keepagr1
LANG: C++
PROG: holstein
*/

#include<iostream>
#include<cstdio>
using namespace std;
const int inf = 100000000;
int v, g;
int need[30];
int feed[20][30];
int ans[20];
int now[30];
int vnow[30];
int cnt;
bool check(){
    for(int i = 0; i < v; i++){
        if(now[i] < need[i]) return false;
    }
    return true;
}
void dfs(int deep, int num){
    if(deep == g) return;
    for(int i = 0; i < v; i++){
        now[i] += feed[deep][i];
    }
    vnow[num] = deep;
    if(check()){
        //printf("%d\n", num);
        if(num < cnt){
            cnt = num;
            for(int i = 1; i <= cnt; i++)
                ans[i] = vnow[i];
        }
    }
    else dfs(deep + 1, num + 1);
    for(int i = 0; i < v; i++)
        now[i] -= feed[deep][i];
    dfs(deep + 1, num);
}
int main(){
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    while(scanf("%d", &v) == 1){
        cnt = inf;
        for(int i = 0; i < v; i++){
            scanf("%d", &need[i]);
        }
        scanf("%d", &g);
        for(int i = 0; i < g; i++)
            for(int j = 0; j < v; j++)
                scanf("%d", &feed[i][j]);
        dfs(0, 1);
        printf("%d ", cnt);
        for(int i = 1; i < cnt; i++)
            printf("%d ", ans[i] + 1);
        printf("%d\n", ans[cnt] + 1);
    }
    return 0;
}