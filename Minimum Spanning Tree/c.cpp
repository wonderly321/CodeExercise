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
#include <math.h>
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
int fa[MAXN];
struct Edge
{
	int u,v,w;
    Edge(){}
    Edge(int u, int v, int w): u(u), v(v), w(w){}
 };
vector<Edge> edges;
int getfa(int x){
    return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}
bool cmp(Edge a, Edge b){
    return a.w < b.w;
}
int main(){
    int n;
    while(cin >> n){
        if(n == 0) break;
        edges.clear();
        for(int i = 0; i < MAXN; i++){
            fa[i] = i;
        }
        for(int i = 0; i < n*(n-1)/2; i++){
            int u, v, w;
            scanf("%d %d %d",&u, &v, &w);
            edges.push_back(Edge(u,v,w));
        }
        sort(edges.begin(),edges.end(),cmp);
        int sum = 0,t = 0;
        for(int i = 0; i < edges.size(); i++){
            int u = getfa(edges[i].u);
            int v = getfa(edges[i].v);
            if(u == v) continue;
            sum += edges[i].w;
            fa[u] = v;
        }
        printf("%d\n",sum);
    }
    return 0;
}


