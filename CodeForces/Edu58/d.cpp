/*
 * Author : Wonderly321
 * Create Time : 2019/1/12 3:40:58
 * File Name : d.cpp
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

const int maxn = 2e5 + 5;

vector<int> G[maxn];
int n;
int a[maxn];
int dp[maxn][7];
vector<int> fac[maxn];

vector<int> primes;
bool boom[maxn];

int ans = 1;

void init() {
    for(int i = 2; i < maxn; i++) {
        if(!boom[i]) {
            primes.push_back(i);
            for(int j = i; j < maxn; j += i) boom[j] = true;
        }
    }
} 

void dfs(int u, int fa) {
    for(int i = 0; i < fac[u].size(); i++) dp[u][i] = 1;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        dfs(v, u);
        for(int j = 0; j < fac[u].size(); j++) {
            for(int k = 0; k < fac[v].size(); k++) {
                if(fac[u][j] == fac[v][k]) {
                    ans = max(ans, dp[u][j] + dp[v][k]);
                    dp[u][j] = max(dp[u][j], dp[v][k] + 1);
                }
            }
        }
    }
}

int main() {
    init();
    scanf("%d", &n);
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(a[i] != 1) flag = false;
        
        for(int j = 0; j < primes.size(); j++) {
            if(primes[j] > a[i]) break;
            if(a[i] % primes[j] == 0) fac[i].push_back(j);
        }
    }
        
    for(int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d",&x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    if(flag) ans = 0;
    else dfs(1, 0);

    cout << ans << endl;

    return 0;
}


