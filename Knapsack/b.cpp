/*
 * Author : Wonderly321
 * Create Time : 2018/12/17 21:28:25
 * File Name : b.cpp
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
#include <queue>

using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

const int MAXN = 12890;
int w[MAXN];
int v[MAXN];
int dp[MAXN];

int solve(int N, int M){
    for(int i = 0 ; i < N ; i++){
        for(int j = M ; j >= 0 ; j--){
            if(j < v[i]) dp[j] = dp[j];
            else dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    return dp[M];
}
int main(){
    int N,M;
    while(cin >> N >> M){
        for(int i = 0 ; i < N ; i++){
            cin >> v[i] >> w[i];
        }
        for(int i = 0 ; i < MAXN ; i++){
            dp[i] = 0;
        }
        cout << solve(N, M) << endl;
        for(int i = 0 ; i < N ; i++){
            w[i] = 0;
            v[i] = 0;
        }
    }
    return 0;
}
