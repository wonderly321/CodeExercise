#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>
#include <utility>
#include <string>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

const int maxn = 300;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

char g[maxn][maxn];
int r,c;

int dist[maxn][maxn];
int vis[maxn][maxn];
vector<pii> ones;

bool check(int x, int y)
{
    return vis[x][y] == 0 && x >= 0 && x < r && y >= 0 && y< c;
}

void bfs()
{
    queue<pii> q;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            dist[i][j] = INT_MAX;
            vis[i][j] = 0;
        }
    }
    for(int i = 0; i < ones.size(); i++) {
        int tx = ones[i].first, ty = ones[i].second;
        dist[tx][ty] = 0;
        vis[tx][ty] = 1;
        q.push(ones[i]);
    }
    while(!q.empty()) {
        int nx = q.front().first, ny = q.front().second;
        q.pop();
        for(int d = 0; d < 4; d++) {
            int tx = nx + dx[d], ty = ny + dy[d];
            if(check(tx,ty)) {
                dist[tx][ty] = min(dist[tx][ty], dist[nx][ny] + 1);
                q.push(make_pair(tx,ty));
                vis[tx][ty] = 1;
            }
        }
    }
}

bool satisfy(int K)
{
    /*
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) cout << dist[i][j];
        cout << endl;
    }
    */
    int add_max = -INT_MAX, sub_max = -INT_MAX;
    int add_min = INT_MAX, sub_min = INT_MAX;
    bool flag = false;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(dist[i][j] > K) {
                add_max = max(add_max, i + j);
                add_min = min(add_min, i + j);
                sub_max = max(sub_max, i - j);
                sub_min = min(sub_min, i - j);
                flag = true;
            }
        }
    }
    if(!flag) return true;
    //cout << add_max << " " << add_min << endl;
    //cout << sub_max << " " << sub_min << endl;
    int ans = INT_MAX;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(g[i][j] == '1') continue;
            int tmp = 0;
            tmp = max(tmp, max(abs(add_max-(i+j)), abs(sub_max-(i-j))));
            tmp = max(tmp, max(abs(add_max-(i+j)), abs(sub_min-(i-j))));
            tmp = max(tmp, max(abs(add_min-(i+j)), abs(sub_max-(i-j))));
            tmp = max(tmp, max(abs(add_min-(i+j)), abs(sub_min-(i-j))));
            ans = min(ans, tmp);
        }
    }
    return ans <= K;
}

int main()
{
    int T,cas = 0;
    cin >> T;
    while(T--){
        scanf("%d%d",&r,&c);
        ones.clear();
        for(int i = 0; i < r; i++) {
            scanf("%s", g[i]);
            for(int j = 0; j < c; j++)
                if(g[i][j] == '1') ones.push_back(make_pair(i,j));
        }
        bfs();

        int L = 0, R = r + c;
        while(L < R) {
            int mid = (L+R) >> 1;
            if(satisfy(mid)) {
                R = mid;
            }
            else {
                L = mid + 1;
            }
        }
        //cout << L << " " << R << endl;
        printf("Case #%d: %d\n", ++cas, L);
    }
    return 0;
}
