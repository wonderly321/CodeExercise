/*
 * Author : Wonderly321
 * Create Time : 2019/1/12 1:38:45
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

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int l,r,d;
        cin >> l >> r >> d;
        if(l > d) {
            cout << d << endl;
            continue;
        }

        cout << (r/d + 1) * d << endl;
    }
    return 0;
}
        
