/*
 * Author : Wonderly321
 * Create Time : 2019/1/12 2:20:24
 * File Name : c.cpp
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

const int maxn = 1e5 + 5;
vector<pii> v;
int ans[maxn];
int n;
int idx[maxn];

bool cmp(int a, int b) {
    return v[a] < v[b];
}

int main() {
    int T, cas = 0;
    cin >> T;
    while(T--) {
        ++cas;
        scanf("%d",&n);
        v.clear();
        for(int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d",&x,&y);
            v.push_back(make_pair(x,y));
            idx[i] = i;
            ans[i] = 2;
        }
//        sort(v.begin(), v.end());
        sort(idx, idx+n, cmp);
        
        int max_left = 0, cnt = 1;
        ans[idx[0]] = 1; max_left = v[idx[0]].second;
        for(int i = 1; i < n; i++) {
            if(v[idx[i]].first <= max_left) {
                ans[idx[i]] = 1;
                max_left = max(max_left, v[idx[i]].second);
                cnt++;
            }
            else {
               break;
            }
        }
        if(cnt == 0 || cnt == n) {
            puts("-1");
            continue;
        }
        for(int i = 0; i < n; i++) {
            printf("%d%c",ans[i],i==n-1?'\n':' ');
        }
    }
    return 0;
}
