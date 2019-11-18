/*
 * Author : Wonderly321
 * Create Time : 2018-12-11 18:30:49
 * File Name : c.cpp
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

const int maxn = 1e5+5;
const int mod = 1e9+7;
int dp[maxn];
int sum[maxn];
int t;
int pre_a = -1,last_a;
int main(){
    string s;
    cin>>s;
    int n = s.length();
    t = n;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a') {
            dp[i] = 1;
            t = i;
            break;
        }
    }
    last_a = t;
    if(t < n) sum[t] = 1;
    else {
        cout<<0<<endl;
        return 0;
    }
    for(int i = t+1; i < n; i++){
        if(s[i] == 'a'){
            if(pre_a == -1){
                dp[i] = 1;
            }
            else{           
                dp[i] = sum[pre_a]+1;
            }
            sum[i] = sum[last_a]+dp[i];
            sum[i]%=mod;
            last_a = i;
        }    
        if(s[i] == 'b'){
            pre_a = last_a;
        }
    }
    cout<<sum[last_a]<<endl;
    return 0;
}
