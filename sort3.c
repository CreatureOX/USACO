/*
ID: keepagr1
LANG: C
PROG: sort3
*/
#include<stdio.h>
#include<stdlib.h>
int raw[1001],sort[1001],i,N;
int cmp(const void *a,const void *b){return *(int *)a - *(int *)b;}
int main(){
	FILE *fin = fopen("sort3.in","r");
	FILE *fout = fopen("sort3.out","w");
    fscanf(fin,"%d",&N);
    for(i=0;i<N;i++){fscanf(fin,"%d",&raw[i]);sort[i]=raw[i];}
    qsort(sort,N,sizeof(int),cmp);
    int x=0,y=0,z=0;  
    for(i=0;i<N;i++){  
        if(sort[i]==1&&raw[i]!=1)x++;  
        else if(sort[i]==2&&raw[i]==3)y++;  
        else if(sort[i]==3&&raw[i]==2)z++;  
    }            
    int cnt = y>z?y:z;  
    cnt += x;
    fprintf(fout,"%d\n",cnt);  
    return 0;
}