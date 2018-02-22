/*
ID: keepagr1
PROG: gift1
LANG: C
*/
#include<stdio.h>
#include<string.h>
char str[15];
int NP;
struct people{
	char name[15];
	int money;
	int remain;
}Friends[11];
int find(){
	int i;
	for(i=0;i<NP;i++)
		if(strcmp(str,Friends[i].name)==0){break;}
	return i;
}
int main () {
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
	int i,j;
	fscanf(fin,"%d",&NP);
	for(i=0;i<NP;i++){
		fscanf(fin,"%s",Friends[i].name);
		Friends[i].remain=0;
	}
	for(j=0;j<NP;j++){
		fscanf(fin,"%s",str);
		int ID = find();
		int sum;
		fscanf(fin,"%d%d",&Friends[ID].money,&sum);
		if(Friends[ID].money){
			int add=Friends[ID].money%sum;
			Friends[ID].remain+=add;}
			for(i=0;i<sum;i++){
				fscanf(fin,"%s",str);
				Friends[find()].remain+=(Friends[ID].money/sum);
			}
	}
	for(i=0;i<NP;i++){
			fprintf(fout,"%s %d\n",Friends[i].name,Friends[i].remain-Friends[i].money);
		}
	return 0;
}
