/*
 * Author : Wonderly321
 * Create Time : 2018-12-12 21:48:16
 * File Name : i.cpp
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


ll dp[31][31];
ll sum[31][31];
int main(){
    int T,cas = 0;
    cin>>T;
    while(T--){
        cas++;
        string s,t;
        cin>>s>>t;
        sum[0][0] = 1;
        for(int i = 1; i <= s.length(); i++){
            sum[i][0] = 1;
        }
        for(int j = 1; j <= t.length(); j++){
            sum[0][j] = 1;
        }
        for(int i = 1; i <= s.length(); i++ ){
            for(int j = 1; j <= t.length(); j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    sum[i][j] = sum[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    if(dp[i-1][j]>dp[i][j-1]){
                        sum[i][j] = sum[i-1][j];
                    }
                    else if(dp[i-1][j]<dp[i][j-1]){
                        sum[i][j] = sum[i][j-1];
                    }
                    else{
                        sum[i][j] = sum[i-1][j]+sum[i][j-1];
                    }
                }
            }
        }
        int num = s.length()+t.length()-dp[s.length()][t.length()];
        ll ans = sum[s.length()][t.length()];
        cout<<"Case "<<cas<<": "<<num<<" "<<ans<<endl;
    }
    return 0;
}
