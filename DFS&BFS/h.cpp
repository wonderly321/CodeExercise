/*
 * Author : Wonderly321
 * Create Time : 2018-12-11 22:54:21
 * File Name : h.cpp
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

using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

char g[25][25];
int m,n;
int cnt = 0;
void dfs(int x,int y){
    if(x >= 0 && x < m && y >= 0 && y < n && g[x][y] != '#'){
        g[x][y] = '#';
        cnt++;
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
    }
}
int main(){
    int T, cas = 0;
    cin>>T;
    while(T--){
        cas++;
        cnt = 0;
        int sx,sy;
        cin>>n>>m;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin>>g[i][j];
                if(g[i][j] == '@'){
                    sx = i;
                    sy = j;
                }
            }
        }
        dfs(sx,sy);
        cout<<"Case "<<cas<<": "<<cnt<<endl;
        
    }
    return 0;
}
