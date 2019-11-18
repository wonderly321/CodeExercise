#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, P;
vector<string> ban;
vector<int> useful;

bool isPrefix(string a, string b)
{
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}
int main()
{
    int T, cas = 0;
    cin >> T;
    while(T--) {
        cin >> N >> P;
        ban.clear();
        useful.clear();
        for(int i = 0; i < P; i++) {
            string tmp;
            cin >> tmp;
            ban.push_back(tmp);
        }
        sort(ban.begin(), ban.end());

        for(int i = 0; i < P; i++) {
            bool flag = true;
            for(int j = i - 1; j >= 0; j--) {
                if(isPrefix(ban[j], ban[i])) {
                    flag = false;
                    break;
                }
            }
            if(flag) useful.push_back(i);
        }
        long long ans = 1LL << N;
        //cout << useful[0] << " " << useful[1] << endl;
        for(int i = 0; i < useful.size(); i++) {
           //     cout << "!" << ban[useful[i]].size() << endl;
            ans -= (1LL << (N - ban[useful[i]].size()));
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}
