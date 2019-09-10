/*
ID : keepagr
TASK:  cowtour
LANG:C++
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
	int x,y;
}a[200];

double m[200][200];
double maxd[200];
double dis(node b,node c){
	return sqrt((c.x-b.x)*(c.x-b.x) + (c.y-b.y)*(c.y-b.y));
}

int main(){
	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
	int n;
	char c;
	cin >> n;
	double temp, mind = 150000;
	for(int i=1; i<=n; i++)
    	cin >> a[i].x >> a[i].y;

	for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
	        cin >> c;
	        if(c=='1')
	        	m[i][j] = dis(a[i],a[j]);
	        else if(i!=j)
	            m[i][j] = 150000;
        }

	for(int i=1; i<=n; i++)
	    for(int j=1; j<=n; j++)
	        for(int k=1; k<=n; k++){
		        if(m[j][k] > m[j][i] + m[i][k])
		            m[j][k] = m[j][i] + m[i][k];
	        }

	for(int i=1; i<=n; i++)
	    for(int j=1; j<=n; j++)
	        if(m[i][j] > maxd[i] && m[i][j] != 150000)
	            maxd[i] = m[i][j];

	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	        if(m[i][j]==150000){
	            temp=dis(a[i],a[j])+maxd[i]+maxd[j];
	            if(temp<mind)
	                mind=temp;
            }

    for(int i=1;i<=n;i++)
        if(maxd[i]>mind)
            mind=maxd[i];

    printf("%.6lf\n",mind);
}

