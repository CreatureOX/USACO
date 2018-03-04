/*
ID: keepagr1
PROG: dualpal
LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[20];
int N,S;
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
int judge(int num){
	int base,count=0;
	for(base=2;base<=10;base++){
		if(isPalindromic(radix(num,base))){count++;}
		if(count==2){return 1;}
	}
	return 0;
}
int main(){
	FILE *fin = fopen("dualpal.in","r");
	FILE *fout = fopen("dualpal.out","w");
	fscanf(fin,"%d %d\n",&N,&S);
	int i,count=0;
	for(i=S+1;count<N;i++){
		if(judge(i)){fprintf(fout,"%d\n",i);count++;}
	}
	return 0;
}