/*
ID：keepagr1
PROG: zerosum
LANG: C
*/
#include<stdio.h>
int n;
int a[10];
int i = 1;
void dfs(int pos, int sum, int pre){
    if(pos == n){
        if(!sum){
            print();
        }
        return ;
    }
    int now = pre *10 + pos + 1;
    a[i++] = 1;
    if(a[i-2] != 3){
        dfs(pos + 1, sum - pre + now, now);
    }else{
        dfs(pos + 1, sum + pre - now, now);       
    }
    a[--i] = 0;
    // 2 means +
    a[i++] = 2;
    dfs(pos + 1, sum + pos + 1, pos + 1);
    a[--i] = 0;
    // 3 means -
    a[i++] = 3;
    dfs(pos + 1, sum - pos - 1, pos + 1);
    a[--i] = 0;
}
void print(){
    for(int j=1;j<=n;j++){
        printf("%d", j);
        if(a[j] == 1){ printf(" "); }
        if(a[j] == 2){ printf("+"); }
        if(a[j] == 3){ printf("-"); }
    }
    printf("\n");
}
int main(){
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
	scanf("%d", &n);
    dfs(1,1,1);

    return 0;
}