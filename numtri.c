/*
ID: keepagr1
LANG: C
PROG: numtri
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000+5
int tri[MAX][MAX];
int R;
int find(){
	int i,j;
	for(i=R-1;i>0;i--)
		for(j=1;j<=i;j++){
			tri[i][j]+=tri[i+1][j]>tri[i+1][j+1]?tri[i+1][j]:tri[i+1][j+1];
		}
	return tri[1][1];
}
int main(){
	FILE *fin = fopen("numtri.in","r");
	FILE *fout = fopen("numtri.out","w");
	fscanf(fin,"%d",&R);
	int i,j;
	for(i=1;i<=R;i++)
		for(j=1;j<=i;j++){
			fscanf(fin,"%d",&tri[i][j]);
		}
	fprintf(fout,"%d\n",find());
	return 0;
}