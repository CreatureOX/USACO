/*
ID: keepagr1
LANG: C
PROG: beads
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int len=0;
char necklace[350];
int fitIndex(int m,int n){
	if(m>=n){m%=n;}
	if(m< 0){m+=n;}
	return m;
}
int nbreak(char* string,int length,int broke){
	int i,pre,pro,total=1;
	int pre_i=broke-1;
    int pro_i=broke+1;
	for(i=0;i<len;i++){
		pre = fitIndex(pre_i--,len);
		if(string[pre]=='w'||string[pre]==string[broke-1])
        {total++;}	
        else if(string[broke-1]=='w'&&string[pre]!='w')
		{total++;string[broke-1]=string[pre];}
		else
        {break;}
	}
    for(i=0;i<len;i++){
		pro = fitIndex(pro_i++,len);        
        if(string[pro]=='w'||string[pro]==string[broke+0])
        {total++;}	
        else if(string[broke+0]=='w'&&string[pro]!='w')
		{total++;string[broke+0]=string[pro];}
        else
        {break;}
    }
	return total>len?len:total;
}
int main(){
	FILE *fin = fopen("beads.in","r");
	FILE *fout = fopen("beads.out","w");
	fscanf(fin,"%d\n",&len);
	fscanf(fin,"%s\n",necklace);
	int i,temp,total=0;
	for(i=0;i<len;i++){
		temp = nbreak(necklace,len,i);
		if(temp>total)
		total = temp;
	}
	fprintf(fout,"%d\n",total);
}