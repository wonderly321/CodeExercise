/*
 * Author : Wonderly321
 * Create Time : 2018/12/27 14:14:07
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

using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

const int MAXN = 50010;

vector<pii> edges;
int father[MAXN];

int getfather(int x){
    return x == father[x] ? x : father[x] = getfather(father[x]);
}

int main(){
    int n, m, cas = 0;
    
    while(cin >> n >>m){
        int ret = 0;
        cas++;
        if(n == 0) break;
        for(int i = 0; i <= n; i++){
            father[i] = i;
        }
        for(int i = 0 ; i < m; i++){
            int u, v;
            scanf("%d %d",&u, &v);
            int x = getfather(u), y = getfather(v);        
            father[x] = y;
        }
        
        
        for(int i = 1; i <= n; i++){
            if(father[i] == i)
                ret++;
        }
        printf("Case %d: %d\n", cas, ret);
    
    }
    
    return 0;
}
