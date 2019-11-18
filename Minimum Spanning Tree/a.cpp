/*
 * Author : Wonderly321
 * Create Time : 2018/12/27 17:33:04
 * File Name : a.cpp
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
struct Edge{
    int u, v, w;
    Edge(){}
    Edge(int _u, int _v, int _w):u(_u), v(_v), w(_w){}
};
bool cmp(Edge a, Edge b){
    return a.w < b.w;
}
int fa[MAXN];
int getfa(int x){
    return x == fa[x] ? x :fa[x] = getfa(fa[x]);
}
vector<Edge> edges;

int main(){
    int n, m, t, tot;
    while(cin >> n >> m && n){
        tot = 0;
        t = 0;
        edges.clear();
        for(int i = 0; i < MAXN; i++){
            fa[i] = i;
        }
        for(int i = 0; i < n; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back(Edge(u, v, w));
        }
        sort(edges.begin(), edges.end(), cmp);

        for(int i = 0; i < n; i++){
            int x =  getfa(edges[i].u);
            int y =  getfa(edges[i].v);
            if(x == y) continue;
            else {
                t++;
                tot += edges[i].w;
                fa[y] = x;                
            }         
        }
        if(t == m-1) cout << tot << endl;
        else cout << "?" << endl; 
    }
    return 0;
}
