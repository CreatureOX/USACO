/*
ID: keepagr1
LANG: C
PROG: barn1
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 200

int stalls[MAX]={0};//stalls
int interval[MAX]={0};//interval
int cmp1(const void *a,const void *b){
	return(*(int *)a-*(int *)b);
}
int cmp2(const void *a,const void *b){
	return(*(int *)b-*(int *)a);
}
int main(){
	FILE *fin=fopen("barn1.in","r");
	FILE *fout=fopen("barn1.out","w");
	int i,M,S,C;
	fscanf(fin,"%d %d %d\n",&M,&S,&C);
	for(i=0;i<C;i++){
		fscanf(fin,"%d\n",&stalls[i]);
	}
	qsort(stalls,C,sizeof(int),cmp1);	
	int sum=stalls[C-1]-stalls[0]+1;
	for(i=1;i<C;i++){
		interval[i]=stalls[i]-stalls[i-1]-1;
	}
	qsort(interval+1,C-1,sizeof(int),cmp2);
	for(i=1;i<M;i++){
		sum-=interval[i];
	}	
	
	fprintf(fout,"%d\n",sum);
	return 0;
}