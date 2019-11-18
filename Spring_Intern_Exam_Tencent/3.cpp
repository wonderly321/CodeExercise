/*
 * Author : Wonderly321
 * Create Time : 2019/4/7 21:05:54
 * File Name : 3.cpp
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


const int maxn = 1e5+5; 
int a[maxn];
int n, k;
vector<int> ans;

int main(){
   while(~scanf("%d %d", &n, &k)){
       ans.clear();
       for(int i = 0; i < n; i++) scanf("%d", a+i);
       sort(a, a+n);
       int idx = 0;
       int tmp = 0;
       for(int i = 0; i < k; i++){
          while(a[idx] <= tmp && idx < n) idx++;
          if(idx >= n) break;
          ans.push_back(a[idx] - tmp);
          tmp =  a[idx];
       }
       if(ans.size() < k){
          for(int i = 0; i <= k-ans.size(); i++){
             ans.push_back(0);
          }
       }
       for(int i = 0; i < k; i++){
          printf("%d %c", ans[i], (i == k-1)?'\n':'\n');
       }
   } 
}
