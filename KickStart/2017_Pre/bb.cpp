/*
 * Author : Wonderly321
 * Create Time : 2019/1/10 14:47:19
 * File Name : bb.cpp
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

int main(){
    int T,cas = 0;
    cin >> T;
    while(T--){
        cas++;
        int n,m;
        cin >> n >> m;
        double ans =  double(n-m)/double(n+m);
        printf("Case #%d: %.8f\n",cas,ans);
    }
    return 0;
}
