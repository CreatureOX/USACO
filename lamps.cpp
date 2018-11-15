/*
ID: keepagr1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <algorithm>
 
using namespace std;
 
int N,C;
vector<int> final_on,final_off;
string s1;
map<int,bool> mymap;
int state6[16];
 
int check(string s){
    for(int i=0;i<final_on.size();i++)
        {if(s[(final_on[i]-1)%6]=='0') return 0;}
    for( int i=0;i<final_off.size();i++)
        {if(s[(final_off[i]-1)%6]=='1')return 0;}
    return 1;
    }
 
int main(){
    ifstream fin("lamps.in");
    ofstream out("lamps.out");
    fin>>N;
    fin>>C;
 
    for(int i=0;fin>>i&&i!=-1;i++)
        final_on.push_back(i);
     for(int i=0;fin>>i&&i!=-1;i++)
        final_off.push_back(i);
 
    int j=0;
    int c=C%2;
    int newstate;
 
    if(c==0){
        newstate=~0;
        if(mymap[newstate]==0)  {state6[j++]=newstate;mymap[newstate]=1;}
 
        if(C>1){
            //0011
            newstate=~42^36;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}
           //0101
            newstate=~36^21;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}
           //0110
            newstate=~42^21;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}
           //1001
            newstate=~36^63;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}
           //1010
            newstate=~42^63;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}
           //1100
            newstate=~21^63;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}
 
           //****1111
           if(C>=4){
             newstate=~21^63^36^42;
            if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
           }
        }
 
    } else {
 
        //****0001 0010 0100 1000
        //0001
        newstate=~36;
        if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
        //0010
        newstate=~42;
        if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
        //0100
        newstate=~21;
        if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
        //1000
        newstate=~63;
        if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
 
        //****0111 1101 1011 1110
        if(C>2){
                //0111
                newstate=~21^42^36;
                if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
                //1101
                newstate=~63^21^36;
                if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
                //1011
                newstate=~63^42^36;
                if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
                //1110
                newstate=~63^42^21;
                if(mymap[newstate]==0) { state6[j++]=newstate; mymap[newstate]=1;}//
        }
    }

    sort(state6,state6+j);
    int flag=0;
    for( int i=0;i<j;i++){
        int  decimal = state6[i];;			
		string s,ss;
		for(int j=5;j>-1;j--){
			if((decimal>>j)&1) ss="1";
			else	ss="0";
			s=s+ss;
		}
 
        if(check(s)){
            for(int i=0;i<N/6;i++) out<<s;
            string sTemp=s.substr(0,N%6);
            out<<sTemp<<endl;
            flag=1;
        }
    }
    if(!flag) {out<<"IMPOSSIBLE"<<endl;}
    return 0;
 
}
