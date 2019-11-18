/*
 * Author : Wonderly321
 * Create Time : 2018-12-11 03:03:16
 * File Name : e.cpp
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

int p,q;
//string ret = "";
char ret[100];
int ret_len = 0;
int cnt = 0;
bool visit[26][26];
const int dx[8] = {-1,1,-2,2,-2,2,-1,1};
const int dy[8] = {-2,-2,-1,-1,1,1,2,2};
bool check(int i,int j){
    if(i >= 0 && i < p && j >= 0 && j < q && visit[i][j] == false)
        return true;
    return false;
}
void dfs(int i,int j){
//    cout << "#" << i << " " << j << " " << ret << " " << cnt << endl;
    for(int d = 0; d < 8; d++){
        if( check(i+dx[d], j+dy[d]) ) {
            visit[i+dx[d]][j+dy[d]] = true;
//            ret+=(char)('A'+j+dy[d]);
//            ret+=toString(i+dx[d]+1);
            ret[ret_len++] = (char)('A'+j+dy[d]);
            ret[ret_len++] = (char)('1'+i+dx[d]);
            cnt++;
            if(cnt == p * q) return;
            dfs(i+dx[d],j+dy[d]);
            if(cnt == p * q) return;

            visit[i+dx[d]][j+dy[d]] = false;
//            ret.resize(ret.length() - 2);
            ret_len -= 2;
            cnt--;
        }
    }
}
int main(){
    int T,cas=0;
    cin>>T;
    while(T--){
        cin>>p>>q;
        printf("Scenario #%d:\n", ++cas);
        if(p > 9){
            puts("impossible\n");
            continue;
        }
        for(int i = 0; i < p; i++){
            for(int j = 0; j < q; j++){
                visit[i][j] = false;
            }
        }
        
        ret_len = 0;
        ret[ret_len++] = 'A';
        ret[ret_len++] = '1';
        cnt = 1;
        visit[0][0] = true;

        dfs(0,0);

//        cout << cnt << endl;
        if(cnt < p*q){
            puts("impossible");
        }
        else {
            for(int i = 0; i < ret_len; i++) putchar(ret[i]);
            puts("");
        }
        if(T > 0) cout<<endl;

    }
    return 0;
}

