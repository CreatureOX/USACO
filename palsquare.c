/*
ID: keepagr1
PROG: palsquare
LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[20];
int B;
int radix(int n,int x)//base 10 to base X
{	int index=0;
		while(n>0)
		{	if(x>10 && n%x>=10)
				{str[index++]= n%x+'A'-10;}
			else
				{str[index++]= n%x+'0';}
			n/=x;
		}
	return index;//MSB index
}
int isPalindromic(int index){
	int i;
	for(i=index-1;i>=index/2;i--){
		if(str[i]!=str[index-i-1]){return 0;}
	}
	return 1;
}
int main(){
	FILE *fin = fopen("palsquare.in","r");
	FILE *fout = fopen("palsquare.out","w");
	fscanf(fin,"%d\n",&B);
	int i,j,index;
	for(i=1;i<=300;i++){
		if(isPalindromic(radix(i*i,B))){
			index=radix(i,B);
			for(j=index-1;j>=0;j--){
				if(j==0){fprintf(fout,"%c ",str[j]);}
				else    {fprintf(fout,"%c",str[j]);}
			}
			index=radix(i*i,B);
			for(j=index-1;j>=0;j--){
				if(j==0){fprintf(fout,"%c\n",str[j]);}
				else    {fprintf(fout,"%c",str[j]);}
			}	
		}
	}
	return 0;
}