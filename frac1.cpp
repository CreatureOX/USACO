/*
ID: keepagr1
LANG: C++
PROG: frac1
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int st[12300];//

int gcd(int a,int b){
	
	return b==0 ? a:gcd(b,a%b);
}

typedef struct fract fract;
struct fract{
	int nmt; //numerator    分子  要求真分数；
	int dnmt; //denominator 分母
};

fract Fract[12300]; //12880

int cmp(int a,int b)
{
	return  (Fract[a].nmt*Fract[b].dnmt<Fract[b].nmt*Fract[a].dnmt)? 1:0;
}

int main()
{	
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	cin>>N;
	int i,j,k=0;
	Fract[0].nmt=0,Fract[0].dnmt=1;k=k+1;
	for(i=1;i<=N;i++)
		for(j=i+1;j<=N;j++)
		{
			if (gcd(i,j)==1) 
			{  Fract[k].nmt=i;
			   Fract[k].dnmt=j;
  		       k++; 
			}
		}

	Fract[k].nmt=1,Fract[k].dnmt=1,k=k+1;

	for (i=0;i<k;i++)
	{
		st[i]=i;
	}

	sort(st,st+k,cmp);

	for (i=0;i<k;i++)
	{
		cout<<Fract[st[i]].nmt<<"/"<<Fract[st[i]].dnmt<<endl;
	}
	
	return 0;
}
