/*
 * Author : Wonderly321
 * Create Time : 2018-12-11 01:23:42
 * File Name : d.cpp
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

int m,n,p;
struct node{
    int x,y,z;
};

const int dz[6] = {1, 0, 0, -1, 0, 0};
const int dx[6] = {0, 1, 0, 0, -1, 0};
const int dy[6] = {0, 0, 1, 0, 0, -1};

node s;
char t[31][31][31];
int visit[31][31][31];
queue<node> q;

bool check(int z, int x, int y) {
    return z >= 0 && z < p && x >= 0 && x < m && y >= 0 && y < n && t[z][x][y] != '#';
}

int main(){
    while(cin>>p>>m>>n){
        if(m == 0) break;
        while(!q.empty()) q.pop();

        for(int i = 0; i < p; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < n; k++){
                    cin>>t[i][j][k];
                    if(t[i][j][k] == 'S'){
                        s.z = i;
                        s.x = j;
                        s.y = k;
                    }
                    visit[i][j][k] = 0;
                }
            }
        }

        visit[s.z][s.x][s.y] = 1;
        q.push(s);
        int ans = -1;

        while(!q.empty()){
            node now = q.front(); q.pop();
            for(int d = 0; d < 6; d++){
                int tx = now.x + dx[d], ty = now.y + dy[d], tz = now.z + dz[d];
                if(!visit[tz][tx][ty] && check(tz,tx,ty)) {
                    q.push((node){tx,ty,tz});
                    visit[tz][tx][ty] = visit[now.z][now.x][now.y] + 1;
                    if(t[tz][tx][ty] == 'E'){
                        ans = visit[tz][tx][ty] - 1;
                        break;
                    }
                }
            }
            if(ans != -1) break; 
        }

        if(ans == -1) puts("Trapped!");
        else printf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}
