/*
 * Author : Wonderly321
 * Create Time : 2018-12-11 22:23:35
 * File Name : g.cpp
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

const int maxn = 20010;
int n;

vector<int> G[maxn];
int vis[maxn];
set<int> S;
int ans1 = 0, ans2 = 0;

void dfs(int x, int color) {
    if(color == 1) ans1++;
    else ans2++;
    vis[x] = color;
    for(int i = 0; i < G[x].size(); i++) {
        int y = G[x][i];
        if(vis[y]) continue;
        dfs(y, 3 - color);
    }
}

int main() {
    int T, cas = 0;
    cin >> T;
    while(T--) {
        S.clear();
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < maxn; i++) G[i].clear();

        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            int u, v;
            scanf("%d %d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
            S.insert(u); S.insert(v);
        }
        
        int ans = 0;
        for(set<int>::iterator it = S.begin(); it != S.end(); it++) {
            int x = *it;
            if(vis[x] == 0) {
                ans1 = ans2 = 0;
                dfs(x, 1);
                ans += max(ans1, ans2);
            }
        }

        printf("Case %d: %d\n", ++cas, ans);
    }
}
