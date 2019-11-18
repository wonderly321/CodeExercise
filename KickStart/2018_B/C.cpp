#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;
using ll = long long;

int N, M;
//int g[1000][1000];
int f[1000][1000];
vector<pii> points;

void init() {
    int A, B, C, D, E, F, v, h;
    cin >> N >> v >> h >> A >> B >> C >> D >> E >> F >> M;

    //clear
    points.clear();
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            f[i][j] = 0;
        }
    }

    f[v][h] = 1;
    points.push_back(make_pair(v,h));
    for(int i = 2; i <= N; i++) {
        int v_new = (A * v + B * h + C) % M;
        int h_new = (D * v + E * h + F) % M;
        v = v_new;
        h = h_new;
        f[v][h] = 1;
        points.push_back(make_pair(v,h));
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            //f[i][j] = g[i][j];
            if(i > 0) f[i][j] += f[i-1][j];
            if(j > 0) f[i][j] += f[i][j-1];
            if(i > 0 && j > 0) f[i][j] -= f[i-1][j-1];
            //f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + g[i][j];
        }
    }
}

int query(int x1, int y1, int x2, int y2) { // exactly inside!!
    if(x1 == x2 || y1 == y2) return 0;
    if(x1 > x2) swap(x1,x2);
    if(y1 > y2) swap(y1,y2);
    int ret = f[x2-1][y2-1];
    ret -= f[x1][y2-1];
    ret -= f[x2-1][y1];
    ret += f[x1][y1];
    return ret;
}

int main()
{
    int T, cas = 0;
    cin >> T;
    while(T--) {
        init();
        ll tot = (ll)N;
        ll ans = tot * (tot-1) / 2 * (tot-2) / 3;
        for(int i = 0; i < N; i++) {
            for(int j = i+1; j < N; j++) {
                int x1 = points[i].first, y1 = points[i].second;
                int x2 = points[j].first, y2 = points[j].second;
                int invalid = query(x1, y1, x2, y2);
                ans = ans - (ll)invalid;
            }
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}
