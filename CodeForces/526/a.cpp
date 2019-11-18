/*
 * Author : Wonderly321
 * Create Time : 2018-12-11 12:20:54
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

using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

int a[100];
int ret,ans=inf;
int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int  i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ret+=(abs(i-j)+j+i)*2*a[j];
        }
        ans=min(ans,ret);
    }
    cout<<ans<<endl;
    return 0;
}
