/*
 * Author : Wonderly321
 * Create Time : 2018/12/19 20:54:32
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
#include <cmath>

using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}


int sgn(double x) {
    if (x > eps) return 1;
    if (x < -eps) return -1;
    return 0;
}

const int maxn = 110;
int n;
int g[maxn][maxn];
vector<pii> p;
queue<int> q;
double dis[maxn];
bool vis[maxn];
int pre[maxn];
double steplen;

void spfa(){
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int i = 0; i <= n; i++) {
            if(sgn(g[u][i] - sqr(steplen))<=0) {
                if(dis[i] > dis[u] + sqrt(g[u][i])){
                    dis[i] = dis[u] + sqrt(g[u][i]);
                    pre[i] = u;
                    if(!vis[i]){
                        vis[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }
}

int main(){
    while(cin >> n >> steplen){
        for(int i = 0; i < n; i++){
            int x,y;
            cin >> x >> y;
            p.push_back(make_pair(x,y));
        }
        if(n == 0) {
            if( sgn(steplen + 7.5 - 50) >= 0 ) {
                cout << 42.5 << " " << 1 << endl;
            }
            else puts("can't be saved");
            continue;
        }
        bool flag = false;
        for(int i = 0; i < maxn; i++) {
            dis[i] = inf; 
            vis[i] = false;
            pre[i] = -1;
        }
        for(int i = 0; i < n; i++){
            if(sgn(sqr(p[i].first)+sqr(p[i].second) - sqr(7.5+steplen))<=0) {
                flag = true;
                q.push(i);
                dis[i] = 0;
                vis[i] = true;
            }
        }
        if(flag == false){
            cout << "can't be saved" << endl;
          continue;
        }
        for(int i = 0; i < n-1; i++){
            for(int j = i+1 ; j < n; j++){
                g[i][j] = sqr(p[i].first-p[j].first)+sqr(p[i].second-p[j].second);
                g[j][i] = g[i][j];
            }
        }
        
        // new node id = n
        for(int i = 0; i < n; i++) {
            g[i][n] = min( sqr(50 - abs(p[i].first)) , sqr(50 - abs(p[i].second)) );
            g[n][i] = g[i][n];
        }
        spfa();

        int now = n;
        int step = 0;
        while(pre[now] != -1) {
//            ans += sqrt(1.0 * g[now][pre[now]]);
            now = pre[now];
            step++;
        }
        double ans = sqrt(sqr(p[now].first)+sqr(p[now].second)) - 7.5;
        if(dis[n] == inf) puts("can't be saved");
        else cout << dis[n] + ans << " " << step + 1 << endl;
    }
    return 0;
}
