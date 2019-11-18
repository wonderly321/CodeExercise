/*
 * Author : Wonderly321
 * Create Time : 2018-12-15 00:56:34
 * File Name : o.cpp
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

vector<int> g[110];
int dis[110];
int dis1[110];
bool vis[110];
queue<int> q;
int ans;
void spfa(int st){
    for(int i = 0; i < 110; i++){
        dis[i] = inf;
        vis[i] = false;
    }
    q.push(st);
    vis[st] = true;
    dis[st] = 0;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        vis[tmp] = false;
        for(int i = 0; i < g[tmp].size(); i++){
            if(dis[g[tmp][i]] > dis[tmp] + 1){
                dis[g[tmp][i]] = dis[tmp] + 1;
                if(vis[g[tmp][i]] == false){
                    q.push(g[tmp][i]);
                    vis[g[tmp][i]] = true;
                }

            }
        }
    }
}
int main(){
    int T,cas = 0;
    cin>>T;
    while(T--){
        for(int i = 0; i < 110; i++){
            g[i].clear();
        }
        ans = 0;
        cas++;
        int n,r,s,t;
        cin>>n>>r;
        for(int i = 0; i < r; i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cin>>s>>t;
        spfa(s);
        for(int i = 0 ; i < n; i++){
            dis1[i] = dis[i];
        }
        //cout << dis[0] << " " << dis[1] << " " << dis[2] << " " << dis[3] << endl;
        spfa(t);
        for(int i = 0; i < n; i++){
            dis1[i] += dis[i];
            ans = max(ans,dis1[i]);
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
