/*
 * Author : Wonderly321
 * Create Time : 2018-12-10 22:07:01
 * File Name : b.cpp
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

char m[20][20];
int ret;
int w,h;
void dfs(int x,int y){
    if(x>=0 && x < w && y >=0 && y < h && m[x][y] =='.' ){
        ret++;
        m[x][y] = '#';
    }
    else{
        return;
    }
    dfs(x,y+1);
    dfs(x,y-1);
    dfs(x-1,y);
    dfs(x+1,y);
}

int main(){
    while(cin>>h>>w){
        int sx,sy;
        ret = 0;
        if(w == 0 && h == 0) break;
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                cin>>m[i][j];
                if(m[i][j] == '@'){
                    m[i][j] = '.';
                    sx = i;
                    sy = j;
                }
                    
            }
        }
        dfs(sx,sy);
        cout<<ret<<endl;
        
    }
    return 0;
}
