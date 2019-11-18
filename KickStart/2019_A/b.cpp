#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>
#include <utility>
#include <string>

using namespace std;

int main(){
    int T,cas = 0;
    cin >> T;
    while(T--){
        cas ++;
        int r, c;
        cin >> r >> c;
        vector<string> g(r);
        vector<pair<int, int> > ones;
        vector< vector<int> > minsv(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++){
            cin >> g[i];
            for(int j = 0; j< c; j++){
                if(g[i][j] == '1')
                    ones.push_back(make_pair(i,j));
            }
        }

        for(int i = 0 ; i < r; i++){
            for(int j = 0; j < c; j++){
                if(g[i][j] == '1') {
                    minsv[i][j] =0;
                    continue;
                }
                minsv[i][j] = INT_MAX;
                for(int k = 0 ; k < ones.size();k++){
                    int dx = ones[k].first;
                    int dy = ones[k].second;
                    minsv[i][j] = min(minsv[i][j], abs(dx - i) + abs(dy - j));
                }
            }
        }

        int ans = INT_MAX;
        for(int i = 0 ; i < r; i++){
            for(int j = 0; j < c; j++){
                if(g[i][j] == '1') {
                    continue;
                }
                int tmp = 0;
                for (int m = 0; m < r; m++){
                    for(int n = 0; n < c; n++){
                        tmp = max(tmp, min(minsv[m][n], abs(m - i) + abs(n - j)));
                    }
                }
                ans = min(ans, tmp);
            }
        }
        if(ans == INT_MAX) ans = 0;
        printf("Case #%d: %d\n",cas, ans);
        minsv.clear();
        ones.clear();
    }
    return 0;
 }
