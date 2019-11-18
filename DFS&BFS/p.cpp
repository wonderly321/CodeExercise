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

char  g[210][210];
int dis[210][210];
bool vis[210][210];
queue<pii> q;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int m,n;
void spfa(int stx, int sty){
    for(int i = 0; i < 210; i++){
        for(int j = 0; j < 210; j++) {
            dis[i][j] = inf;
            vis[i][j] = false;
        }
    }
    q.push(make_pair(stx,sty));
    vis[stx][sty] = true;
    dis[stx][sty] = 0;
    while(!q.empty()){
        pii tmp = q.front();
        q.pop();
        vis[tmp.first][tmp.second] = false;
        for(int d = 0; d < 4; d++){
            int tx = tmp.first + dx[d];
            int ty = tmp.second + dy[d];
            if(tx < 0 || tx >= m || ty < 0 || ty >= n || g[tx][ty] == '#') continue;
            int w = 1;
            if(g[tx][ty] == 'x'){
                w = 2;
            }
            if(dis[tx][ty] > dis[tmp.first][tmp.second] + w){
                dis[tx][ty] = dis[tmp.first][tmp.second] + w;
                if(vis[tx][ty] == false){
                    q.push(make_pair(tx,ty));
                    vis[tx][ty] = true;
                }

            }
        }
    }
}
int main(){

    while(cin>>m>>n){
        int stx, sty;
        for(int i = 0; i < m; i++){
            scanf("%s",g[i]);
            for(int j = 0; j < n; j++) {
                if(g[i][j] == 'a') {
                    stx = i;
                    sty = j;
                }
            }
        }
        spfa(stx, sty);
        int ans = inf;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][j] == 'r') ans = min(ans, dis[i][j]);
            }
        }
        if(ans == inf) puts("Poor ANGEL has to stay in the prison all his life.");
        else printf("%d\n",ans);
    }
    return 0;
}
