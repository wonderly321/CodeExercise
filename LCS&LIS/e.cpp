/*
 * Author : Wonderly321
 * Create Time : 2018-12-08 21:49:13
 * File Name : e.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <ctime>
#include <sstream>

using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

string dp[101][101];
int main(){
    int T,cas=0;
    cin>>T;
    while(T--){
        cas++;
        string s,t;
        cin>>s>>t;
        int m = s.length();
        int n = t.length();
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + s[i-1];
                }
                else{
                    if(dp[i-1][j].length() > dp[i][j-1].length()){
                        dp[i][j] = dp[i-1][j];
                    }
                    else if(dp[i-1][j].length() < dp[i][j-1].length()){
                        dp[i][j] = dp[i][j-1];
                    }
                    else{
                        if(dp[i-1][j] > dp[i][j-1])
                            dp[i][j] = dp[i][j-1];
                        else
                            dp[i][j] = dp[i-1][j];
                            
                    }
                }          
                
            }
        }
        if(dp[m][n].length() == 0)
            cout<<"Case "<<cas<<": "<<":("<<endl;
        else
            cout<<"Case "<<cas<<": "<<dp[m][n]<<endl ;
    }
    return 0;
}
