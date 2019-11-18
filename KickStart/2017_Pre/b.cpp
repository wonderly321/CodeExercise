/*
 * Author : Wonderly321
 * Create Time : 2019/1/10 13:03:42
 * File Name : b.cpp
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
#include <cmath>
using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

const int maxn=2e3+10;

double dp[maxn][maxn];
void init()
{

    for(int i = 0; i < maxn; i++)
    {
        for(int k = 0; k < maxn; k++)
        {
            dp[i][k] = -1;
        }    
    }
    dp[0][0] = log(1.0);
    for(int i = 0; i < maxn; i++)
    {
        for(int k = 0; k < maxn; k++)
        {
            if(i > k)
            {
                if(dp[i-1][k] != -1 && dp[i][k-1] != -1)
                {
                    dp[i][k] = dp[i-1][k] + log(1 + exp(dp[i][k-1] - dp[i-1][k]));    
                }    
                else if(dp[i-1][k] != -1)
                {
                    dp[i][k] = dp[i-1][k];
                }
                else if(dp[i][k-1] != -1)
                {
                    dp[i][k] = dp[i][k-1];
                } 
            }    
        }
    }
}
int main()
{
    init();
    int T,cas = 0;
    cin >> T;
    while(T--){
        cas++;
        int n,m; 
        cin >> n >> m;
        double ans=0;
        for(int i=1;i <= m;i++)
        {
            ans += (double)log(i) - (double)log(n+i);
        }
        ans += (double)dp[n][m];
        ans = exp(ans);
        printf("Case #%d: %.8f\n",cas,ans);     
    }  
}
