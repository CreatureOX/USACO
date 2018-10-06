/*
ID: [keepagr1]
PROG: skidesign
LANG: C
*/
#include<stdio.h>
#include<stdlib.h>

int N;
int hills[1000];
int main(){
	FILE *fin = fopen("skidesign.in","r");
	FILE *fout = fopen("skidesign.out","w");
	fscanf(fin,"%d\n",&N);
	int low,i,min=1000000000;
	for(low=0;low<N;low++){
		fscanf(fin,"%d\n",&hills[low]);
	}
	for(low=0;low<=83;low++){
		int money=0;
		for(i=0;i<N;i++){
			if(hills[i]<low){
				money+=(low-hills[i])*(low-hills[i]);
			}
			if(hills[i]>low+17){
				money+=(hills[i]-low-17)*(hills[i]-low-17);
			}
		}
		if(money<min){min=money;}
	}
	fprintf(fout,"%d\n",min);
	return 0;
}