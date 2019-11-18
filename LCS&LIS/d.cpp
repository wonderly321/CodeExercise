/*
 * Author : Wonderly321
 * Create Time : 2018-12-08 21:26:09
 * File Name : d.cpp
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

using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

int m, n;
char s[110], t[110];
int dp[110][110];
int score(char a,char b){
    if(a == b)
        return 5;
    if((a == 'C' && b == 'G')||(a == 'G' && b == 'C')||(a == 'A' && b == '-')||(a == '-' && b == 'A'))
        return -3;
    if((a == 'G' && b == 'A')||(a == 'A' && b == 'G')||(a == 'C' && b =='T')||(a == 'T' && b == 'C')||(a == '-' && b == 'G')||(a == 'G' && b == '-')||(a == 'T' && b =='G')||(a == 'G' && b == 'T'))
        return -2;
    if((a == 'A' && b == 'T')||(a == 'T' && b == 'A')||(a == 'A' && b == 'C')||(a == 'C' && b == 'A')||(a == 'T' && b == '-')||(a == '-' && b == 'T'))
        return -1;
    if((a == 'C' && b == '-')||(a == '-' && b == 'C'))
        return -4;
    return 0;
}
int main(){
    
    int T;
    cin>>T;
    while(T--){
        scanf("%d %s", &m, s+1);
        scanf("%d %s", &n, t+1);
        for(int i = 1; i <= m; i++) dp[i][0] = dp[i-1][0] + score(s[i],'-');
        for(int j = 1; j <= n; j++) dp[0][j] = dp[0][j-1] + score(t[j],'-');
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = max(dp[i-1][j-1] + score(s[i],t[j]) , max(dp[i][j-1] + score('-',t[j]) , dp[i-1][j]+score(s[i],'-')));
            }
        }
        
        cout<<dp[m][n]<<endl;
    }
    return 0;
}
