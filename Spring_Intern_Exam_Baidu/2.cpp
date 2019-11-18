/*
 * Author : Wonderly321
 * Create Time : 2019/4/2 18:37:00
 * File Name : 2.cpp
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

int p[110];
vector<int> cont;
void kmp_init(string s){
    p[0] = -1;
    int j = -1;
    for(int i = 1; i < (int)s.length(); i ++){
        while(j > -1 && s[j+1] != s[i])
            j = p[j];
        if(s[j+1] == s[i]) j++;
        p[i] = j;
    }
}
bool kmp(string s, string t){
    kmp_init(t);
    int j = -1;
    for(int i = 0; i < (int)s.length(); i++){
        while(j > -1 && t[j+1] != s[i]) j= p[j];
        if(t[j+1] == s[i]) j++;
        if(j == (int)t.length()-1) cont.push_back(i);
    }
    return false;
}
int main(){
    string a,b;
    int q;
    cin >> a;
    cin >> b;
    cin >> q;
    kmp(a,b);
    int len = cont.size();
    for(int j = 0; j < q; j++){
        int x, y;
        scanf("%d %d",&x, &y);
        x -= 1;
        y -= 1;
        int cnt = 0;
        for(int i = 0; i < len; i++ ){
            if(cont[i]-(int)b.length()+1 >= x  && cont[i] <= y)
                cnt ++;
        }
        printf("%d\n",cnt);
    }
    
}
