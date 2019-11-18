/*
 * Author : Wonderly321
 * Create Time : 2018/12/21 22:49:37
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
const int MAXN = 1010;
int n,m;
vector<int> g[MAXN];
queue<int> q;
bool vis[MAXN];
int dis[MAXN],pre[MAXN];
vector<int> path;
struct Edge{
    int from,to,len;
    Edge(){}
    Edge(int from, int to, int len):from(from),to(to),len(len){}
};
vector<Edge> edges;

void spfa(int s, bool first){
    for(int i = 0; i < MAXN ; i++){
        dis[i] = inf;
        pre[i] = -1;
        vis[i] = false;
    }
    q.push(s);
    vis[s] =  true;
    dis[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = 0; i < g[u].size(); i++){
            int v = edges[g[u][i]].to;
            int w = edges[g[u][i]].len;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pre[v] = g[u][i];
                if(vis[v] == false){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(!first) return;
    int x = n;
    while(x!=s){
        path.push_back(pre[x]);
        x = edges[pre[x]].from;     
    }
    
}
int main(){  
    while(~scanf("%d %d", &n, &m)){       
        int ans = -inf;
        path.clear();    
        for(int i = 0; i < 1010; i++) g[i].clear();
        for(int i = 0 ; i < m; i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edges.push_back(Edge(u,v,w));
            edges.push_back(Edge(v,u,w));
            g[u].push_back(edges.size()-2);
            g[v].push_back(edges.size()-1);
        }
        spfa(1, true);
        for(int i = 0; i < path.size(); i++){
            int len = edges[path[i]].len;
            edges[path[i]].len = inf;
            spfa(1, false);
            ans = max(ans,dis[n]);
            edges[path[i]].len = len;
        }
        printf("%d\n",ans);
    
    }
    return 0;
}
