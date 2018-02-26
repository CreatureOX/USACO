/*
ID: keepagr1
PROG: transform
LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
int N;
char **raw;
char **chg;
char** rotate(char **pic){
	int i,j;
	char **data;
    data=(char **)malloc(N*sizeof(char *));  
	 for (int i=0;i<N;i++)  
        data[i]=(char *)malloc(N*sizeof(char)); 
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			data[i][j]=pic[N-j-1][i];
		}
	return data;
	free(data);	
}
char** reflect(char** pic){
	int i,j;
	char** data;
    data=(char **)malloc(N*sizeof(char *));  
	 for (int i=0;i<N;i++)  
        data[i]=(char *)malloc(N*sizeof(char)); 

	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			data[i][j]=pic[i][N-j-1];
		}		
	return data;
	free(data);	
}
int judge(char** src,char** dst){
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			if(src[i][j]!=dst[i][j])	return 0;
		}
	return 1;
}
int menu(char **pic,char **target){
	if(judge(rotate(pic),target)) 							    return 1;
	else if(judge(rotate(rotate(pic)),target))					return 2;
	else if(judge(rotate(rotate(rotate(pic))),target))	 		return 3;
	else if(judge(reflect(pic),target))							return 4;
	else if(judge(rotate(reflect(pic)),target))					return 5;
	else if(judge(rotate(rotate(reflect(pic))),target))			return 5;
	else if(judge(rotate(rotate(rotate(reflect(pic)))),target))	return 5;
	else if(judge(pic,target)) 									return 6;
	else														return 7;
}
int main(){
	FILE *fin = fopen("transform.in","r");
	FILE *fout = fopen("transform.out","w");
	fscanf(fin,"%d\n",&N);
	int i,j;	
	raw=(char **)malloc(N*sizeof(char *));  
	for (int i=0;i<N;i++)  
		raw[i]=(char *)malloc(N*sizeof(char)); 
	chg=(char **)malloc(N*sizeof(char *));  
	for (int i=0;i<N;i++)  
		chg[i]=(char *)malloc(N*sizeof(char)); 
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			if(j==N-1){fscanf(fin,"%c\n",&raw[i][j]);}
			else      {fscanf(fin,"%c",&raw[i][j]);}
		}
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			if(j==N-1){fscanf(fin,"%c\n",&chg[i][j]);}
			else      {fscanf(fin,"%c",&chg[i][j]);}
		}
	fprintf(fout,"%d\n",menu(raw,chg));
}