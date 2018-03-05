/*
ID: keepagr1
LANG: C
PROG: milk
*/
#include<stdio.h>
#include<stdlib.h>

#define MAXFARMER 5000

typedef struct Farmer Farmer;
struct Farmer{
	int p;// price
	int a;// amount
};

int farmcmp(const void *a,const void *b){
	return ((Farmer*)a)->p-((Farmer*)b)->p;
}

int nfarmer;
Farmer farmer[MAXFARMER];

int main(){
	FILE *fin=fopen("milk.in","r");
	FILE *fout=fopen("milk.out","w");
	int i,n,a,p;
	fscanf(fin,"%d %d\n",&n,&nfarmer);
	for(i=0;i<nfarmer;i++){
		fscanf(fin,"%d %d\n",&farmer[i].p,&farmer[i].a);
	}
	qsort(farmer,nfarmer,sizeof(farmer[0]),farmcmp);
	
	p=0;
	for(i=0;i<nfarmer&&n>0;i++){
		a=farmer[i].a;
		if(a>n)
			a=n;
		p+=a*farmer[i].p;
		n-=a;
	}
	
	fprintf(fout,"%d\n",p);
	return 0;
}