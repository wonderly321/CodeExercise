/*
 * Author : Wonderly321
 * Create Time : 2019/1/6 1:09:45
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

using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

const int maxn = 4010;
double dp[1100000];
double a[22];

int main(){
    int n;
	while(~scanf("%d",&n))
	{
		double t = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%lf",&a[i]);
			t += a[i];
		}
		t = 1-t;
		memset(dp,0,sizeof(dp));
		int m = (1 << n) - 1;
		dp[m] = 0;
 
		for(int sta = m-1; sta >= 0; sta--)
		{
			double s1 = 0,s2 = 0;
			for(int j = 0; j < n; j++)
			{
				if(!(sta & (1<<j)))
				{
					s1 += a[j] * dp[sta|(1<<j)];
				}
				else
					s2 += a[j];
			}
			s1 += 1;
			dp[sta] = s1/(1-s2-t);
		}
		printf("%.4lf\n",dp[0]);
	}
    return 0;
}
