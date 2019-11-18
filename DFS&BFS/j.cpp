/*
 * Author : Wonderly321
 * Create Time : 2018-12-13 10:23:30
 * File Name : j.cpp
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

char g[11][11];
int step[11][11];
bool vis[11][11];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
map<int,pii> m;
int n;

bool check(int x,int y){
   if( x >= 0 && x < n && y >= 0 && y < n && g[x][y]!= '#' && vis[x][y] == false)
       return true;
   return false;
}
int find(pii st, int ed) {
    g[st.first][st.second] = '.';
    char end = ed+'A';
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            vis[i][j] = false;
        }
    }
    vis[st.first][st.second] = true;
    queue<pii> q;
    q.push(st);
    step[st.first][st.second]=0;
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = p.first+dx[i];
            int ny = p.second+dy[i];
            if(check(nx,ny)){
                if(g[nx][ny] != '.' && g[nx][ny] != end) vis[nx][ny] = true;
                else if(g[nx][ny] == '.' ){ 
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
    cin>>T;
    while(T--){
        ans = 0;
        cas++;
        cin>>n;
        m.clear();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin>>g[i][j];
                if(g[i][j]>= 'A' &&g[i][j] <= 'Z'){
                    m[(int)(g[i][j]-'A')] = make_pair(i,j);
                }
            }
        }
        int k = m.size();
        for(int i = 0; i < k-1; i++){
            int steps=find(m[i],i+1);
            if(steps == -1){
                ans = -1;
                break;
            }
            ans+=steps;
        }
        if(ans == -1)
            cout<<"Case "<<cas<<": "<<"Impossible"<<endl;
        else cout<<"Case "<<cas<<": "<<ans<<endl;
    }
    return 0;
}
