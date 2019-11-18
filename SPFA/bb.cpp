/*
 * Author : Wonderly321
 * Create Time : 2018/12/20 22:23:18
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

const int MAXN = 110;
vector<int> g[MAXN];
int score[MAXN], dis[MAXN],times[MAXN];
bool vis[MAXN];
queue<int> q;
int n;
int fa[MAXN];

int getfather(int x){
    return x == fa[x] ? x : fa[x] = getfather(fa[x]);
}

bool spfa(int s){
    while(!q.empty()) q.pop();
    for(int i = 0; i < MAXN ; i++){
     vis[i] = false;
     dis[i] = -inf;
     times[i] = 0;
    }
    q.push(s);
    vis[s] = true;
    dis[s] = 100+score[s];
    times[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = 0 ; i < g[u].size(); i++){
            int v = g[u][i];
            if(dis[v] < dis[u] + score[v] && dis[u] + score[v] > 0){
                dis[v] = dis[u] + score[v];
                if(vis[v] == false){
                    q.push(v);
                    times[v]++;
                    if(times[v] >= n + 10) return getfather(v)==getfather(n);
                    vis[v] = true;
                }
            }
        }
    }
    if(dis[n] <= 0)
        return false;
    return true;
}
int main(){
    
    while(~scanf("%d",&n)){
        if(n == -1) break;
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 1; i <= n; i++){            
            int cnt;
            scanf("%d%d",&score[i],&cnt);
            for(int j = 0; j < cnt; j++){
                int tmp;
                cin >> tmp;
                g[i].push_back(tmp); 
                int u = getfather(i);
                int v = getfather(tmp);
                fa[u] = v;
            }            
        }
//        for(int i = 0 ; i < MAXN; i++){
//            vis[i] = false;
//        }
        if(spfa(1))
            puts("winnable");
        else puts("hopeless"); 
        
    }
    return 0;
}
