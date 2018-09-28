/*
ID: keepagr1
LANG: C
PROG: sprime
*/
#include<stdio.h>
#include<math.h>
int N;
int mark=0;
int ans[99999999];
int isPrime(int n){
	int i;
	for(i=2;i<sqrt(n);i++){
		if(n%i==0) return 0;
	}
	return 1;
}
void dfs(int dep,int num){
	int i;
	if(dep==N){FILE *fout = fopen("sprime.out","a");fprintf(fout,"%d\n",num);fclose(fout);}
	for(i=0;i!=10;++i){if(isPrime(num*10+i)){dfs(dep+1,num*10+i);}}
}
int main(){
	FILE *fin = fopen("sprime.in","r");
	FILE *fout = fopen("sprime.out","a");
	fscanf(fin,"%d",&N);
	dfs(1,2);
	dfs(1,3);
	dfs(1,5);
	dfs(1,7);
	fclose(fout);
	return 0;	
}