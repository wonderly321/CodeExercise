/*
 * Author : Wonderly321
 * Create Time : 2019/4/7 19:20:18
 * File Name : 1.cpp
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

int main(){
    int n,k;
    while(cin >> n >> k){
        int count = 0;
        while(n/2>0){
           count++;
           if(n%2 == 0) 
               n = n/2;
           else {               
               n = (n/2) + 1;
               if(n/2 == 1) break;
           }
           if(count == k) break;
        }
        if(count < k)
            printf("%d\n",count + n);
        else printf("%d\n",k + n);
            
    }
    return 0;
}

