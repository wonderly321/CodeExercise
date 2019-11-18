/*
 * Author : Wonderly321
 * Create Time : 2019/1/6 19:10:25
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


int getdifferent(string s){
    sort(s.begin(),s.end());
    return unique(s.begin(),s.end())-s.begin() - (s[0]==' '?1:0);     
}
int main(){
    int T, cas = 0;
    cin >> T;
    while(T--){
        cas++;
        int n, maxlen = -1;
        cin >> n;
        getchar();
        vector<string> v;
        for(int i = 0; i < n; i++){
            string s;
            getline(cin,s);
            int len = getdifferent(s);
            if(len > maxlen){
                v.clear();
                v.push_back(s);
                maxlen = len;
            }
            else if(len == maxlen){
                v.push_back(s);
            }
            
        }
        sort(v.begin(), v.end());
        printf("Case #%d: %s\n", cas, v[0].c_str());
        
    }
    return 0;
}

