/*
 * Author : Wonderly321
 * Create Time : 2018-12-14 14:13:42
 * File Name : n.cpp
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

queue<int> q;
int dis[1010];
bool vis[1010];
vector<int> pri;
int ans;
int s,t;

bool IsPrime(int x){
    for(int i = 2; i < x; i++){
        if(x%i == 0)
            return false;
    }
    return true;
}
void spfa(int s){
    for(int i = 0;i <= t; i++){
        dis[i] = inf;
        vis[i] = false;
    }
    q.push(s);
    vis[s] =  true;
    dis[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int j = 0; pri[j] < u ;j++){
            if(u%pri[j] == 0){
                int v = u + pri[j];
                if(v > t) break;
                if(dis[v]>dis[u]+1){
                     dis[v] = dis[u]+1;
                     if(vis[v] == false){
                         q.push(v);
                         vis[v] = true;
                     }
                }      
            }
        }
    }
}


int main(){
    int T,cas = 0;
    scanf("%d",&T);
    while(T--){
        cas++;
        scanf("%d %d",&s,&t);
        pri.clear();
        for(int i = 2; i <= 1000; i++ ){
            if(IsPrime(i)) {
                pri.push_back(i); 
            }
        }
        spfa(s);
        printf("Case %d: %d\n",cas,dis[t]==inf?-1:dis[t]);
    }
    return 0;
}
