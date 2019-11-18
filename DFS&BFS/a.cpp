/*
 * Author : Wonderly321
 * Create Time : 2018-12-10 19:48:58
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

using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

const int N =14;
int a[N],ans[N];
bool visit[N];
int n;
void dfs(int i, int k){
    if(k == 6){
        for(int i = 0; i < 6; i++){
//            cout<<ans[i];
//            if(i == 5)
//                cout<<endl;
//            else cout<<" ";
            printf("%d%c", ans[i], i==5?'\n':' ');
        }
        return;
    }
    for(int j = i; j < n; j++){
        if(visit[j] == false){
            visit[j] = true;
            ans[k] = a[j];
            dfs(j+1,k+1);
            visit[j] = false;
        }
    }
}

int main(){
    bool first = false;
//    while(cin >> n){
    while(~scanf("%d",&n)) {
        if(n == 0) break;
        if(first) cout<<endl;
        first = true;
        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
        }
        dfs(0,0);
        
    }
    return 0;
}
