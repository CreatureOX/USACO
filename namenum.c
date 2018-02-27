/*
ID: keepagr1
PROG: namenum
LANG: C
*/
#include<stdio.h>
#include<string.h>
char data[5000][15];
int count;//count 
char ID[15];//The number
char out[15];//out data 
int len;// ID actual digit
int flag=0;// whether has name
int visit[12][3]={0};
char PAD[10][3]={
	"000","000",
	"ABC","DEF","GHI",
	"JKL","MNO","PRS",
	"TUV","WXY"
};
void putin(){
	count=0;
	FILE *dict = fopen("dict.txt","r");
	while(!feof(dict)){fscanf(dict,"%s",data[count++]);}
}
int check(char str[]){
	int res=-1;
	int l=0,r=count-1;
	while(l<=r){
		int mid=(l+r)/2;
		int mark=strcmp(data[mid],str);
		if(mark==0)	   {res=mid;break;}
		else if(mark>0){r=mid-1;}
		else		   {l=mid+1;}
	}
	return res==-1?0:1;
}
void dfs(int dep,char str[]){
	int i;

	if(dep==len){	
		out[dep+1]='\0';
		//printf("%s\n",out);
		if(check(out)){printf("%s\n",out);}
		if(check(out)){
			FILE *fout = fopen("namenum.out","a");
			//fseek(fout,0L,SEEK_END);
			fprintf(fout,"%s\n",out);
			fclose(fout);
			flag=1;
			}		
		return;
	}
	for(i=0;i<3;i++){
		if(visit[dep][i]==0){
			out[dep]=PAD[ID[dep]-'0'][i];			
			visit[dep][i]=1;
			dfs(dep+1,str); 
			visit[dep][i]=0;			
		}
	}	
}
int main(){
	FILE *fin = fopen("namenum.in","r");
	FILE *fout = fopen("namenum.out","w");
	putin();
	fscanf(fin,"%s\n",ID);	
	len=strlen(ID);
	dfs(0,ID);
	if(!flag){fprintf(fout,"NONE\n");fclose(fout);}
	return 0;
}