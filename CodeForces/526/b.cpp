/*
 * Author : Wonderly321
 * Create Time : 2018-12-11 12:55:11
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

using namespace std;

#define inf 0x3f3f3f3f
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define clr(x) memset(x,0,sizeof(x))
typedef long long ll;
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

ll v[1010];
ll sum = 0;
int main(){
    int n;
    ll s;
    cin>>n>>s;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        sum += v[i];
    }
    sort(v,v+n);
    if(sum < s) cout<<-1<<endl;
    else{
        ll avg = (sum-s)/n;
        if(avg <= v[0])
            cout<<avg<<endl;
        else{
            cout<<v[0]<<endl;
        }
    }

    return 0;
}
