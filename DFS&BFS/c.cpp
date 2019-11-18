/*
 * Author : Wonderly321
 * Create Time : 2018-12-10 22:49:09
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

int sum,n;

string ret = "";

int a[12];
bool visit[12]; 
bool flag = false;

vector<string> ans;

void dfs(int sum, int j){
//    cout << "#" << sum << " " << j << " " << ret << endl;
    if(sum == 0){
        flag = true;
        for(int i = 0; i < ans.size(); i++) 
            if(ans[i] == ret) return;
        ans.push_back(ret);
        return;
    }
    else{
        for(int i = j; i < n; i++){
            if(sum < a[i]) continue;
            if(visit[i] == false){
                visit[i] = true;
                string tmp = toString(a[i]);
                if(sum > a[i]) tmp += "+";
                ret += tmp;

                dfs(sum - a[i], i + 1);
                
                visit[i] = false;
                ret.resize(ret.length() - tmp.length());
            }
        }
    }
    
}

int main(){
    while(cin>>sum>>n){
        if(sum == 0 && n == 0) break;
        ans.clear();
        flag = false;
        for(int i = 0; i < n; i++){
            cin>>a[i];
        }
        cout<<"Sums of "<<sum<<":"<<endl;
        dfs(sum, 0);
        if(flag == false)
            cout<<"NONE"<<endl;
        else  {
//            int m = unique(ans.begin(), ans.end()) - ans.begin();
            for(int i = 0; i < ans.size(); i++) 
                cout << ans[i] << endl;
        }
    }
    return 0;
}
