/*
 * Author : Wonderly321
 * Create Time : 2018/12/20 11:02:05
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

int n, x[MAXN], y[MAXN], pre[MAXN];
double d, m[MAXN][MAXN], dis[MAXN];
queue<int> q;
bool vis[MAXN];

void spfa(int s,int t){
    for(int i = 0; i <= n+1; i++ ){
        vis[i] = false;
        dis[i] = inf;
        pre[i] = -1;
    }
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        vis[tmp] = false;
        for(int i = 0; i <= n+1; i++){
            if(dis[i] > dis[tmp] + m[tmp][i]){
                dis[i] = dis[tmp] + m[tmp][i];
                pre[i] = tmp;
                if(vis[i] == false){                  
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    if(dis[t] >= inf){
        cout << "can't be saved" << endl;
        return;
    }
    int e = t,step = 0;
    while(e != s){
        step++;
        e = pre[e];
    }
//    cout << dis[t] << " " << step << endl;
    printf("%.2f %d\n",dis[t], step);
    return;
}
int main(){
    
    while(cin >>n >> d){
        if(n == 0){
            if(d >= 42.5)
                cout << "42.50 1" << endl;
            else
                cout << "can't be saved" << endl;
            continue;
        }
        for(int i = 1 ; i <= n ; i++){ 
            cin >> x[i] >> y[i];              
        }
        x[0] = y[0] = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                m[i][j] = sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
                if((i||j)&&!(i&&j)) 
                    m[i][j] -= 7.5;
                m[i][j] = max(m[i][j],0.0);
                if(m[i][j] > d) 
                    m[i][j] = inf;
            }
        }
        for(int i = 0; i <= n; i++){
          double r = min(50-abs(x[i]),50-abs(y[i]));
          if(r > d){
              r = inf;
          }
          m[i][n+1] = m[n+1][i] = r;               
        }        
        spfa(0,n+1);
    }
    return 0;
}

