/*
 * Author : Wonderly321
 * Create Time : 2018-12-13 21:57:00
 * File Name : l.cpp
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
typedef pair<int, int> pii;

bool vis[21][21];
int step[21][21];
char g[21][21];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m,n;
bool check(int x,int y){
   if( x >= 0 && x < m && y >= 0 && y < n && g[x][y]!= '#' && g[x][y]!= 'm' && vis[x][y] == false)
       return true;
   return false;
}
int find(int sx,int sy, int ex, int ey) {
    g[sx][sy] = '.';
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 21; j++){
            vis[i][j] = false;
            step[i][j] = 0;
        }
    }
    vis[sx][sy] = true;
    queue<pii> q;
    q.push(make_pair(sx,sy));
    step[sx][sy]=0;
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(check(nx,ny)){
                if(g[nx][ny] == '.'||g[nx][ny] == 'a'||g[nx][ny] == 'b'||g[nx][ny] == 'c'){ 
                    vis[nx][ny] = true;
                    step[nx][ny]=step[p.first][p.second]+1;
                    q.push(make_pair(nx,ny));
                }
                else return step[p.first][p.second]+1;
            }
        }
    }
    return -1;
}
int main(){
    int T,cas = 0;
    int ans;
    int ax = 0, ay = 0, bx = 0, by = 0, cx = 0, cy = 0, hx = 0, hy = 0;
    cin>>T;
    while(T--){
        ans = 0;
        cas++;
        cin>>m>>n;    
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin>>g[i][j];
                if(g[i][j] == 'a'){
                   ax = i;
                   ay = j;
                }
                else if(g[i][j] == 'b'){
                    bx = i;
                    by = j;
                }
                else if(g[i][j] == 'c'){
                    cx = i;
                    cy = j;
                }
                else if(g[i][j] == 'h'){
                    hx = i;
                    hy = j;
                }
            }
        }
        int ans1=find(ax,ay,hx,hy);
        int ans2=find(bx,by,hx,hy);
        int ans3=find(cx,cy,hx,hy);
        ans = max(ans3,max(ans2,ans1));
    
        cout<<"Case "<<cas<<": "<<ans<<endl;
    }
    return 0;
}
