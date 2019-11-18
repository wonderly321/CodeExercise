/*
 * Author : Wonderly321
 * Create Time : 2018-12-13 16:30:14
 * File Name : k.cpp
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

typedef pair<int,int> pii;

const int MAXN=30010;
vector<pii> g[MAXN];
bool vis[MAXN];
int ret,pos;

void dfs(int x,int sum){
    for(int i = 0; i < g[x].size(); i++){
        int t = g[x][i].first;
        int dis = g[x][i].second;
        if(vis[t] == false){           
            vis[t] = true;
            if(dis + sum > ret){               
                 ret = dis+sum;
                 pos = t;
            }
            dfs(t,dis+sum);
        }       
    }
}
int main(){
    int T,cas = 0;
    cin>>T;
    while(T--){
        cas++;
        int n;
        ret = -1,pos = -1;
        cin>>n;
        for(int i = 0; i < n-1; i++){
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        for(int j = 0; j < n; j++){
            vis[j] = false;
        }
        vis[0] = true;
        dfs(0,0);
        ret = -1;
        for(int j = 0; j < n; j++){
            vis[j] = false;
        }
       
        vis[pos] = true;
        dfs(pos,0);
        cout<<"Case "<<cas<<": "<<ret<<endl;
        for(int k = 0; k < n; k++){
                g[k].clear();
        }
    }
    return 0;
}
