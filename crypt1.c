/*
ID: keepagr1
PROG: crypt1
LANG: C
*/
#include<stdio.h>
#include<string.h>
int hash[10];
int check(int x){
	while(x){
		if(!hash[x%10]){
			return 1;
		}
			x/=10;
	}
	return 0;
}
int main(){
    FILE *fin  = fopen ("crypt1.in", "r");
    FILE *fout = fopen ("crypt1.out", "w");
	int sum = 0;
	int N;
	fscanf(fin,"%d",&N);
	int t,i,j;
	for(i=0;i<N;i++){
		fscanf(fin,"%d",&t);
		hash[t] = 1;
	}
	for(i=100;i<1000;i++){
		if(check(i)){continue;}
		for(j=10;j<100;j++){
			int m,m1,m2;
			m = i*j;
			if(m>9999){break;}
			if(check(j)||check(m)){continue;}
			m1 = (j%10)*i;
			if(m1<100||m1>=1000){continue;}
			m2 = (j/10)*i;
			if(m2<100||m2>=1000){continue;}
			if(check(m2)||check(m1)){continue;}
			sum++;
		}
	}
	fprintf(fout,"%d\n",sum);
	return 0;
}