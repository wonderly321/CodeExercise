#include <iostream>
#include <cstdio>

using namespace std;

string s,t;
int dp[1001][1001];
int main(){
    while(cin >> s >> t) {

        for(int i = 1; i <= s.length(); i++){
            for(int j = 1; j <= t.length(); j++){
                    if(s[i-1]==t[j-1]){
                        dp[i][j]=dp[i-1][j-1] + 1;
                    }
                    else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }

            }
        }
        cout << dp[s.length()][t.length()] << endl;
    }
    return 0;
}
