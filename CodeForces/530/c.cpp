/*
 * Author : Wonderly321
 * Create Time : 2019/1/12 20:40:01
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
int k;

int main() {
    cin >> s;
    cin >> k;
    int n = s.length();
    
    int cane_num = 0, snow_num = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') cane_num++;
        if(s[i] == '*') snow_num++;
    }

    string ret = "";
    if(k == n - cane_num - snow_num) {
        for(int i = 0; i < n; i++) {
            if(s[i] == '?') continue;
            if(s[i] == '*') continue;
            ret += s[i];
        }
    }
    else if(k < n - cane_num - snow_num) {
        if(k < n - cane_num * 2 - snow_num * 2) {
            puts("Impossible");
            return 0;
        }
        int del = n - cane_num - snow_num - k;        
        for(int i = 0; i < n; i++) {
            if(s[i] == '?' && del > 0) {
                ret.resize(ret.size()-1);
                del--;
            }
            if(s[i] == '*' && del > 0) {
                ret.resize(ret.size()-1);
                del--;
            }
            if(s[i] != '?' && s[i] != '*') ret += s[i];
        }
    }
    else { // k > n - cane_num - snow_num
        if(snow_num == 0) {
            puts("Impossible");
            return 0;
        }
        int add = k - n + cane_num + snow_num;
        for(int i = 0; i < n; i++) {
            if(s[i] != '?' && s[i] != '*') ret += s[i];
            if(s[i] == '?') continue;
            if(s[i] == '*' && add > 0) {
                for(int k = 0; k < add; k++) ret+=s[i-1];
                add = 0;
            }
        }   
    }
    cout << ret << endl;
    return 0;
}
