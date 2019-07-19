/*
ID:keepagr1
LANG:C++
TASK:prefix
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
 
vector <string> p_set;
string s_seq;
int dp[200000+10];
int max(int a,int b){return a>b? a:b;}
 
int main(){
    ifstream in("prefix.in");
    ofstream out("prefix.out");
 
    for(string s;in>>s&&s!=".";)
        p_set.push_back(s);
    for(string s;in>>s;)
		s_seq=s_seq+s;
 
    dp[0]=0;
    for(unsigned int i=1;i<=s_seq.size();i++){//动态规划，背包问题？一定顺序放物品
        if(i>0) dp[i]=dp[i-1];
        for(int unsigned j=0;j<p_set.size();j++){//元素集合p
            string s1=p_set[j];        //遍历集合p中的字符串
            unsigned int t1=s1.size(); //元素t1的长度
 
            if(i>=t1&&s_seq.substr(dp[i-s1.size()],s1.size())  ==s1){
              //S的子字符串长度大于元素s1的长度，且元素s1是S的后缀
                if(i-s1.size()==0||dp[i-s1.size()]!=0)//要么s1就是前缀，要么s1是出现在S的某个前缀后
                    dp[i]=max(dp[i],dp[i-s1.size()]+s1.size());
            }
        }
    }
    out<<dp[s_seq.size()]<< endl;
    return 0;
}
