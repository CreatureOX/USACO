/*
ID: keepagr1
PROG: friday
LANG: C
*/
#include<stdio.h>
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int week[8]={0};
int leap(int x){
	return (x%4==0&&x%100!=0)||x%400==0?1:0;
}
int main(){
	FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");
	int N,i,j,last=1;
	fscanf(fin,"%d",&N);
   for(i=0;i<N;++i){
        for(j=1;j<=12;++j){
            last+=12;
            week[last%7]++;
            if(j==2 && leap(1900 + i)) last+=29-12;
            else last+=month[j]-12;
        }
    }
    printf("%d %d %d %d %d %d %d\n",week[6],week[0],week[1],week[2],week[3],week[4],week[5]);
    return 0;
}