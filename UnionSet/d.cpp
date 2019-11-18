/*
 * Author : Wonderly321
 * Create Time : 2018/12/27 16:32:11
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
typedef pair<int,int> pii;
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
const int MAXN = 50010;

#define rank sdfda
int father[MAXN];
int rank[MAXN];
int getfather(int x){
    if(x == father[x])
        return x
    int tmp = father[x];
    father[x] = getfather(father[x]);
    rank[x] = (rank[x]+rank[tmp])%3;
    return father[x];
}

int main(){
//    freopen("d.in", "r", stdin);
//    freopen("d.txt", "w", stdout);
    int n,k;
    int ret = 0;
    cin >> n >> k;
    for(int i = 0; i <= n; i++){
        father[i] = i;
        rank[i] = 0;
    }
    for(int i = 0; i < k; i++){
        int d, x, y;
        scanf("%d %d %d",&d, &x, &y);
        d--;
        if(x > n || y > n) {
            ret++;
            continue;
        }
        int u = getfather(x);
        int v = getfather(y);
        if(u == v && ((rank[x]-rank[y]+3)%3 != d)) ret++;
        if(u != v){
            father[u] = v;
            rank[u] = (d+rank[y]-rank[x]+3)%3;
        }
    }
    printf("%d\n", ret);
    return 0;
}
