#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
using namespace std;

using ll = unsigned long long;

ll nine[20];

ll count(ll n){
    ll res = 0LL;
    string sn = to_string(n);

    int l = sn.length();
    for(int i = 0; i < l; i++){
        if(i < l-1){
            res+=(ll)(sn[i]-'0')*nine[l-i-2];
            //cout << "#" << res << endl;
        }
        else{
            for(ll j = n - n%10;j <= n; j++){
                if(j%9 > 0)
                    res+=1LL;
            }
        }
    }
    return res;
}
int main(){
    int T,cas = 0;
    nine[0] = 8;
    for(int i = 1; i < 20; i++) nine[i] = nine[i-1] * 9LL;
    cin>>T;
    while(T--){
        cas++;
        ll f,l;
        cin >> f >> l;
        printf("Case #%d: %llu\n",cas,count(l)-count(f)+1);
    }
    return 0;
}
