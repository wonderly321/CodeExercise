/*
 * Author : Wonderly321
 * Create Time : 2019/1/10 21:42:34
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

const long long mod = 1e9+7;
long long n,m;
long long queen(long long x,long long another){
    if(another==1){
        return x;
    }
    long long res;
    res = queen(x, another/2)%mod;
    res = (res*res)%mod;
    if(another%2){
        res = (res*x)%mod;
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    int rnd = 1;
    while(t--){
        scanf("%lld%lld",&n,&m);
        if(n>m){
            swap(n,m);
        }
        n--,m--;
        long long k;
        long long res = -1;
        res = 0;
        long long now = (((n*m)%mod + (m+n+1)%mod)%mod);
        k = ((1+n)*n/2)%mod;
        now = (now * k)%mod;
        res = (res+now)%mod;
        now = (n+m+2)%mod;
        k = (((n*(n+1))%mod)*(2*n+1)%mod*queen(6,mod-2))%mod;
        res = (res - k*now)%mod;
        if(res<0){
            res += mod;
        }
        k = ( ((n*(n+1)/2)%mod) * ((n*(n+1)/2)%mod) )%mod;
        res = (res + k)%mod;
        printf("Case #%d: %lld\n",rnd++,res);
    }
    
    return 0;
}
