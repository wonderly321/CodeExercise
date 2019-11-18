#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

const int maxn = 1e6 + 6;

struct node
{
    int l, r, len;
};

bool cmp(node a, node b) {
    if(a.len != b.len) return a.len < b.len;
    return a.l < b.l;
}

int n, q;
vector<node> v;
bool avail[maxn];

int main()
{
    int T,cas = 0;
    cin >> T;
    while(T--){
        scanf("%d %d",&n, &q);
        v.clear();
        memset(avail, 0, sizeof(avail));
        for(int i = 0; i < q; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            v.push_back(node{x, y, y-x+1});
        }
        sort(v.begin(), v.end(), cmp);
        int ans = INT_MAX;
        for(int i = 0; i < q; i++) {
            int l = v[i].l, r = v[i].r, len = v[i].len;
            int tmp = 0;

            for(int j = l - 1; j <= r - 1; j++) {
                if(avail[j] == true) {
                    tmp++;
                }
                else {
                    avail[j] = true;
                }
            }

            ans = min(ans, len-tmp);
        }
        printf("Case #%d: %d\n",++cas, ans);
    }
    return 0;
}
