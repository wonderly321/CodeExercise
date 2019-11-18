#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int dp[31][31];
long long tot[31][31];
string s, t;

int main(){
    int T,cas=0;
//    init();
    cin >> T;
    while(T--){
        cin>>s>>t;

        for(int i = 0; i <= s.length(); i++) tot[i][0] = 1;
        for(int i = 0; i <= t.length(); i++) tot[0][i] = 1;

        for(int i = 1; i <= s.length(); i++){
            for(int j = 1; j <= t.length(); j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    tot[i][j] = tot[i-1][j-1];
                }
                else {
                    if (dp[i-1][j] > dp[i][j-1]) {
                        dp[i][j] = dp[i-1][j];
                        tot[i][j] = tot[i-1][j];
                    }
                    else if(dp[i][j-1] > dp[i-1][j]){
                        dp[i][j] = dp[i][j-1];
                        tot[i][j] = tot[i][j-1];
                    }
                    else {
                        dp[i][j] = dp[i][j-1];
                        tot[i][j] = tot[i-1][j] + tot[i][j-1];
                    }
                }
            }
        }
        int clen=dp[s.length()][t.length()];
        int ret1=s.length()+t.length()-clen;
        cout << "Case " << ++cas << ": " << ret1 << " " << tot[s.length()][t.length()] << endl;
    }


    return 0;
}
