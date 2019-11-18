/*
 * Author : Wonderly321
 * Create Time : 2018-12-13 23:15:05
 * File Name : m.cpp
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
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
typedef pair<int,int> pii;

int m,n,q;
char g[510][510];
bool vis[510][510];
int ans[510][510];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pii> p;
vector<int> cnt;
#define count djkhsf 
int count;
bool check(int x,int y){
   if( x >= 0 && x < m && y >= 0 && y < n && g[x][y]!= '#' && vis[x][y] == false)
       return true;
   return false;
}

int find(int sx,int sy) {
    int count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            vis[i][j] = false;
        }
    }
    vis[sx][sy] = true;
    if(g[sx][sy] == 'C') count++;
    queue<pii> q;
    vector<pii> v;
    q.push(make_pair(sx,sy));

    while(!q.empty()){
        pii p=q.front();
        v.push_back(p);
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(check(nx,ny)){
                vis[nx][ny] = true;
                q.push(make_pair(nx,ny));
                if(g[nx][ny] == 'C'){ 
                    count++;
                }
            }
        }
    }

    for(int i = 0; i < v.size(); i++) {
        ans[v[i].first][v[i].second] = count;
    }
    return count;
}

/*
void dfs(int x, int y){
    if(check(x,y)){
        vis[x][y]=true;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            dfs(nx,ny);
        }
        if(g[x][y]=='C'){
            count++;
        }
    }

}
*/
int main(){
    int T,cas = 0;
    cin>>T;
    while(T--){
        cas++;
        scanf("%d%d%d",&m,&n,&q);
        cnt.clear();
        for(int i = 0; i < m; i++){
            scanf("%s", g[i]);
        }
        for(int i = 0; i < m; i++) {
            clr(vis);
            memset(ans, -1, sizeof(ans));
        }
        for(int k = 0; k < q; k++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(ans[x-1][y-1] == -1) {
                ans[x-1][y-1] = find(x-1, y-1);
            }
            cnt.push_back(ans[x-1][y-1]);
        }
        printf("Case %d:\n",cas);
        for(int i = 0; i < cnt.size(); i++){
            printf("%d\n",cnt[i]);
        }

    }
    return 0;
}
