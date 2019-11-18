/*
 * Author : Praesidio
 * Create Time : 2018-12-08 21:00:01
 * File Name : c.cpp
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
int lis[40001];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,len=0;
        lis[0] = 0;
        cin>>n;
        for(int i = 1; i <= n; i++){
            int x;
            cin>>x;
            if(lis[len]<x){
                len++;
                lis[len]=x;
            }
            else{
                int pos = lower_bound(lis,lis+len+1,x)-lis;
                lis[pos] = x;
            }
             
        }
        cout<<len<<endl;
    } 
    return 0;
}
