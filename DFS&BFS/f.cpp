/*
 * Author : Wonderly321
 * Create Time : 2018-12-11 00:27:22
 * File Name : f.cpp
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


char g[110][110];
bool visit[110][110];
int ret=0,m,n;
void dfs(int i,int j){
    if(g[i][j] == '*'||i < 0||i >= m||j < 0||j >= n||visit[i][j] == true)
        return;
    visit[i][j]=true;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i,j+1);
    dfs(i-1,j-1);
    dfs(i-1,j+1);
    dfs(i+1,j-1);
    dfs(i+1,j+1);
}
int main(){
    while(cin>>m>>n){
        ret = 0;
        if(m == 0 && n == 0) break;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin>>g[i][j];
                visit[i][j] = false;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visit[i][j] && g[i][j] == '@'){
                    dfs(i,j);
                    ret++;
                }
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}
