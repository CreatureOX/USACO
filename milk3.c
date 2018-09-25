/*
ID: keepagr1
LANG: C
PROG: milk3
*/
#include<stdio.h>
#include<stdlib.h>
int A,B,C;
int visit[21][21][21],amount[21];
void milk(int a,int b,int c){
	if(visit[a][b][c]) return;
	if(!a) amount[c]=1;
	visit[a][b][c]=1;
	b+c>B?milk(a,B,b+c-B):milk(a,b+c,0);
	a+c>A?milk(A,b,a+c-A):milk(a+c,b,0);
	c+b>C?milk(a,c+b-C,C):milk(a,0,c+b);
	a+b>A?milk(A,a+b-A,c):milk(a+b,0,c);
	b+a>B?milk(b+a-B,B,c):milk(0,b+a,c);
	c+a>C?milk(c+a-C,b,C):milk(0,b,c+a);
	
}
int main(){
	FILE *fin = fopen("milk3.in","r");
	FILE *fout = fopen("milk3.out","w");
	fscanf(fin,"%d%d%d",&A,&B,&C);
	milk(0,0,C);
	int i,st=1;
	for(i=0;i<21;i++){
		if(amount[i]&&st==0){fprintf(fout," %d",i);}
		if(amount[i]&&st==1){fprintf(fout,"%d",i);st=0;}
	}
	fprintf(fout,"\n");
	return 0;
}