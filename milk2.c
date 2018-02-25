/*
ID: keepagr1
PROG: milk2
LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
int time[500000+10]={0};
int N;
int start,end;
int realstart=5000+10;
int realend=-1;
int flag=-1;
int worktime=0;
int resttime=0;
int longestworktime=0;
int longestresttime=0;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int main(){
	FILE *fin = fopen("milk2.in","r");
	FILE *fout = fopen("milk2.out","w");
	fscanf(fin,"%d\n",&N);
	int i;
	while(N--){
		fscanf(fin,"%d %d\n",&start,&end);
		for(i=start+1;i<=end;i++){time[i]=1;}			
		realend=max(realend,end);
		realstart=min(realstart,start);
	}
	
	for(i=realstart;i<=realend;i++){
		if(flag==-1&&time[i]==1){
            flag=1;worktime++;
        }else if(flag==-1&&time[i]==0){
            flag=0;resttime++;
        }else if(flag==1&&time[i]==1){
            worktime++;
        }else if(flag==1&&time[i]==0){
            flag = 0;
            longestworktime = max(longestworktime,worktime);
            worktime = 0;
            resttime = 1;
        }else if(flag==0&&time[i]==1){
            flag=1;
            longestresttime = max(longestresttime,resttime);
            worktime = 1;
            resttime = 0;
        }else if(flag==0&&time[i]==0){
            resttime++;
        }
	}
	
    fprintf(fout,"%d %d\n",max(longestworktime,worktime),max(longestresttime,resttime));
	return 0;
}