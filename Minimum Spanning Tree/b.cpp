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
vector<pii> p;
struct Edge
{
	int u,v;
	double cost;
    Edge(){}
    Edge(int u, int v, double w): u(u), v(v), cost(w){}
 };
vector<Edge> edges;
int getfa(int x){
    return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}
bool cmp(Edge a, Edge b){
    return a.cost < b.cost;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        edges.clear();
        p.clear();
        for(int i = 0; i < MAXN; i++){
            fa[i] = i;
        }
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            p.push_back(make_pair(x,y));
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                double d = sqrt(sqr(p[i].first-p[j].first)+sqr(p[i].second-p[j].second));
                if(d < 10 || d > 1000) continue;
                edges.push_back(Edge(i, j, d));                
            }
        }
        sort(edges.begin(),edges.end(),cmp);
        double sum = 0,t = 0;
        for(int i = 0; i < edges.size(); i++){
            int u = getfa(edges[i].u);
            int v = getfa(edges[i].v);
            if(u == v) continue;
            sum += edges[i].cost;
            t++;
            fa[u] = v;
                
        }
        if(t == n-1)
            printf("%.1f\n",sum*100);
        else
            puts("oh!\n"); 
    }
    return 0;
}

