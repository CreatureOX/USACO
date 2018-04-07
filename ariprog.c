 /*
ID: keepagr1
LANG: C
PROG: ariprog
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 125000+4
int N,M;
int arr[MAX];
int main(){
	FILE *fin = fopen("ariprog.in","r");
	FILE *fout = fopen("ariprog.out","w");
	fscanf(fin,"%d%d",&N,&M);
	int b,a;
	for(b=0;b<=M;b++)
		for(a=0;a<=M;a++){
			arr[b*b+a*a]=1;
		}
	int flag=0;int limit=2*M*M;
	for(b=1;b<=limit/(N-1);b++){
		for(a=0;a+(N-1)*b<=limit;a++){
			int cnt=0;int temp;
			for(temp=a;temp<=limit;temp+=b){
				if(arr[temp]==1){cnt++;}
				else		  {break;}
				if(cnt==N)	  {break;}
			}
			if(cnt==N){flag=1;fprintf(fout,"%d %d\n",a,b);}
		}
	}
	if(flag==0){fprintf(fout,"NONE\n");}
	return 0;
}