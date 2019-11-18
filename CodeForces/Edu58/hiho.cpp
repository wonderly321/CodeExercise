#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> pii;
#define inf 0x3f3f3f3f

const int maxn = 810;

queue<int> q;
vector<int> G[maxn*maxn];
bool vis[maxn*maxn];
int dist[maxn*maxn];
int n,m;

void spfa() {
    for(int i = 0; i <= n * m; i++) dist[i] = inf;
    
    dist[0] = 0;
    vis[0] = 1;
    q.push(0);
    
    while(!q.empty()) {
        int u = q.front(); q.pop(); vis[u] = 0;
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if(v < 0 || v > n * m) continue;
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
char s[maxn];
int main() {
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for(int j = 1; j <= m; j++) {
            char x = s[j];
            int enc = m * (i-1) + j;
            if(x == '0') {
                G[0].push_back(enc);
                G[enc].push_back(0);
            }
            if(j > 1) G[enc].push_back(enc-1);
            if(j < m) G[enc].push_back(enc+1);
            if(i > 1) G[enc].push_back(enc-m);
            if(i < n) G[enc].push_back(enc+m);
        }
    }
    spfa();
    for(int i = 1; i <= n * m; i++) {
        printf("%d%c", dist[i] - 1, i % m == 0?'\n':' ');
    }
    return 0;
}
