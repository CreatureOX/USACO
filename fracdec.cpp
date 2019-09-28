/*
ID:keepagr1
PROG:fracdec
LANG:C++
*/
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100010;
bool done[maxn] = {0};//对于每一个余数如果重复，则是循环节
int p[maxn], ans[maxn], N,D;//p指向每次除法时余数所对应的答案（编号），ans为小数部分
int cur = 3;

void solve(int num){
   //输出优化 计算出偏移量 比如10.  是占位置的 %64输出需要注意
   int t = 10;
   while(t <= num){
      t *= 10;
      cur++;
   }
}
int main(){
   freopen("fracdec.in", "r", stdin);
   freopen("fracdec.out", "w", stdout);
   memset(p,-1,sizeof(p));
   scanf("%d%d", &N, &D);
   if (N%D == 0){
      printf("%.1f\n", (float)N/D);
   }else{
      solve(N/D);
      printf("%d.",N/D);
		int a = N%D,n = 0;
		while(done[a] == 0){
			if(a == 0){
            //整除 
				for(int i=0;i<n;i++){printf("%d",ans[i]);}
				printf("\n");
				return 0;
			}
			done[a]=1;//余数
			p[a]=n;//更新指向
			ans[n++]=a*10/D;//成为被除数 
			a=(a*10)%D;//成为余数 
		}
		for(int i=0;i<p[a];i++){
         //输出 
			printf("%d",ans[i]);
			if((i+1+cur)%76==0)putchar('\n');
		}  
		putchar('(');
		for(int i=p[a];i<n;i++){
			printf("%d",ans[i]);
				if((i+1+cur)%76==0)putchar('\n');
		}
		printf(")\n"); 
   }
   return 0;
}