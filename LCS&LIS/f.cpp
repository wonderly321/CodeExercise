/*
 * Author : Wonderly321
 * Create Time : 2018-12-08 22:46:44
 * File Name : f.cpp
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

int dp[501][501];
string ret[501][501];
int s[501];
int t[501];

int main(){
    int m,n;
    cin>>m;
    for(int i = 0; i < m ;i++) cin>>s[i];
    cin>>n;
    for(int i = 0; i < n; i++) cin>>t[i];

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <=n; j++){
            if(s[i-1]==t[j-1]){

                int maxlen = 0;
                for(int k = 1; k <= j-1; k++){
                    if(maxlen < dp[i-1][k] && t[k-1] < t[j-1]){
                        maxlen = dp[i-1][k];
                        ret[i][j]=ret[i-1][k];
                    }
                }
                dp[i][j] = maxlen+1;

                if(j < n){
                    ret[i][j] = ret[i][j]+toString(t[j-1])+" ";
                }
                else
                    ret[i][j] = ret[i][j]+toString(t[j-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
                ret[i][j]= ret[i-1][j];
            }
        }
    }

    int ans = 0;
    string ans_s;
    for(int i = 1; i <= n; i++) {
        if(ans < dp[m][i]) {
            ans = dp[m][i];
            ans_s = ret[m][i];
        }
    }
    cout << ans << endl << ans_s << endl;
    return 0;
}
