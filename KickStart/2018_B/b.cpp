#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

using ll = long long;

const int STATE = 1 << 16;
ll dp[110][STATE];
int N, K;
ll P;
int A[110], B[110], C[110];

const ll inf = 1e18;
const int mask = (1<<15) - 1;

int count_one(int now, int st, int ed)
{
    int ret = 0;
    for(int i = st; i <= ed; i++) {
        ret += (now >> (15-i)) & 1;
    }
    return ret;
}

bool satisfy(int last, int x, int n)
{
    int now = last << 1 | n;
    now &= mask;
    for(int i = 0; i < K; i++) {
        if(A[i] >= x-14 && B[i] <= x) {
            if(C[i] != count_one(now, A[i]-x+15, B[i]-x+15)) return false;
        }
    }
    return true;
}

void gao()
{
    for(int x = N; x >= 1; x--) {
        for(int st = 0; st < (1<<15); st++) {
            if(x == N) {
                for(int i = 0; i < 2; i++) {
                    if(satisfy(st, x, i)) {
                        dp[N][st] += 1LL;
                        dp[N+1][(st<<1|i) & mask] = 1LL;
                    }
                }
            }
            else {
                for(int i = 0; i < 2; i++) {
                    if(satisfy(st, x, i)) {
                        dp[x][st] += dp[x+1][(st<<1|i) & mask];
                        dp[x][st] = min(dp[x][st], inf);
                    }
                }
            }
        }
    }
}

int main()
{
    int T, cas = 0;
    cin >> T;
    while(T--) {
        for(int i = 0; i <= 101; i++) {
            for(int j = 0; j < STATE; j++) dp[i][j] = 0LL;
        }

        scanf("%d %d %lld", &N, &K, &P);
        for(int i = 0; i < K; i++) {
            scanf("%d %d %d", A+i, B+i, C+i);
        }

        gao();

        int now = 0;
        string ans = "";
        for(int i = 1; i <= N; i++) {
            ll X = dp[i+1][(now<<1) & mask];
            //cout << X << endl;
            if(X >= P) {
                now = now << 1;
                now &= mask;
                ans += '0';

            }
            else {
                P -= X;
                now = now << 1 | 1;
                now &= mask;
                ans += '1';
            }
        }

        printf("Case #%d: %s\n", ++cas, ans.c_str());
    }
    return 0;
}
