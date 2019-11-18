/*
 * Author : Wonderly321
 * Create Time : 2019/1/12 3:21:01
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

int n;
char s[2];
int h,w;

int main() {
    cin >> n;
    int x = 0, y = 0;
    while(n--) {
        scanf("%s %d %d", s, &h, &w);
        if(s[0] == '+') {
            if(h > w) swap(h,w);
            x = max(x, h);
            y = max(y, w);
        }
        else if(s[0] == '?') {
            if(h > w) swap(h,w);
            if(h >= x && w >= y) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
