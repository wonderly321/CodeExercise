/*
 * Author : Wonderly321
 * Create Time : 2019/1/12 1:46:29
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

string s;

int find(const string& s, int st, char c) {
   for(int i = st; i < (int)s.length(); i++) {
       if(s[i] == c) return i;
   }
   return -1;
}

int find_rev(const string& s, int ed, char c) {
    for(int i = ed; i >= 0; i--) {
        if(s[i] == c) return i;
    }
    return -1;
}

#define check(x) if(x==-1) { cout<<-1<<endl; return 0; }

int main() {
    cin >> s;
    int rr = s.length() - 1;
    
    int l_bra = find(s, 0, '[');
    check(l_bra);
    int r_bra = find_rev(s, rr, ']');
    check(r_bra);
    int l_colon = find(s, l_bra, ':');
    check(l_colon);
    int r_colon = find_rev(s, r_bra, ':');
    check(r_colon);
    
    if(l_bra >= r_bra || l_colon >= r_colon) {
        cout << -1 << endl;
        return 0;
    }
    int ret = 4;
    for(int i = l_colon; i <= r_colon; i++) {
        if(s[i] == '|') ret++;
    }
    cout << ret << endl;
    return 0;
}
