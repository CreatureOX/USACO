/* 
LANG: C 
ID: keepagr1
PROG: ttwo 
*/  
#include <stdio.h>  
#define init(a,c) if(map[i][j]==c){a[0]=i; a[1]=j; map[i][j]='.';}

char map[11][11];
char way1[4] = {-1,0,1,0};
char way2[4] = {0,1,0,-1};
char farmer[4],cow[4];

void move(char *n){  
    int i,j;
    i = n[0] + way1[n[2]];
    j = n[1] + way2[n[2]];
    if(i>10||i<1||j>10||j<1||map[i][j] == '*'){
        n[2] = (n[2]+1)%4;
    }else{
        n[0] = i;
        n[1] = j;
    }
}

int main(){
    int i,j;
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            scanf("%c",&map[i][j]);
            init(farmer,'F');
            init(cow,'C');
        }
        getchar();
    }
    for(i = 0;i<160000&&(farmer[0]!=cow[0] || farmer[1]!=cow[1]);i++){
        move(farmer);
        move(cow);
    }
    printf("%d\n", i%160000);
    return 0;
}  