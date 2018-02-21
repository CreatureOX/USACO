/*
ID: keepagr1
PROG: ride
LANG: C
*/
#include<stdio.h>
#include<string.h>
char s1[11],s2[11];
int main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
	int prod1,prod2,i;
	while(fscanf(fin,"%s%s",s1,s2)!=EOF){
		prod1=prod2=1;
		for(i=0;i<strlen(s1);i++){prod1*=(s1[i]-'A'+1);}
		for(i=0;i<strlen(s2);i++){prod2*=(s2[i]-'A'+1);}	
		if(prod1%47==prod2%47)
			{fprintf(fout,"GO\n");}
		else
			{fprintf(fout,"STAY\n");}
	}
	return 0;
}
