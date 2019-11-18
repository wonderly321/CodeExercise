#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;
const int maxn = 200010;
const long long mod = 1e9 + 7;

int N, M;

long long f[maxn];
long long invf[maxn];
long long two[maxn];

ll exgcd(ll l,ll r,ll &x,ll &y)
{
    if(r==0){x=1;y=0;return l;}
    else
    {
        ll d=exgcd(r,l%r,y,x);
        y-=l/r*x;
        return d;
    }
}

ll mod_inverse(ll a,ll m){
    ll x,y;
    if(exgcd(a,m,x,y)==1)//ax+my=1
        return (x%m+m)%m;
    return -1;//²»´æÔÚ
}

void init()
{
    f[0] = 1;
    for(int i = 1; i <= 200002; i++) {
        f[i] = i * f[i-1] % mod;
    }

    for(int i = 0; i <= 200002; i++) {
        invf[i] = mod_inverse(f[i], mod);
    }

    two[0] = 1LL;
    for(int i = 1; i <= 200002; i++) {
        two[i] = 2LL * two[i-1] % mod;
    }
}

int main()
{
    init();
    int T, cas = 0;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        long long ans = f[N << 1];
        //cout << ans << endl;
        for(int i = 1; i <= M; i++) {
            //cout << two[i] * f[M] % mod * invf[M-i] % mod * f[(N<<1)-i] % mod << endl;
            if(i&1) {
                ans = ans - two[i] * f[M] % mod * invf[M-i] % mod * invf[i] % mod * f[(N<<1)-i] % mod;
                ans = (ans + mod) % mod;
            }
            else{
                ans = ans + two[i] * f[M] % mod * invf[M-i] % mod * invf[i] % mod * f[(N<<1)-i] % mod;
                ans %= mod;
            }
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
}
