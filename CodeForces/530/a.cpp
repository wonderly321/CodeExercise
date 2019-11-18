/*
 * Author : Wonderly321
 * Create Time : 2019/1/12 20:15:00
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

int w, h;
int u1, u2, d1, d2;

int main() {
    cin >> w >> h;    
    cin >> u1 >> d1;
    cin >> u2 >> d2;
    if(d1 < d2) swap(d1,d2), swap(u1,u2);
    int ret = w;
    for(int i = h; i >= 0; i--) {
        ret += i;
        if(i == d1) {
            ret -= u1;
            ret = max(ret, 0);
        }
        else if(i == d2) {
            ret -= u2;
            ret = max(ret, 0);
        }
    }
    cout << ret << endl;
    return 0;
}
        
