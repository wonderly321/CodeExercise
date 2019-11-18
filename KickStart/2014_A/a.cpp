#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
map<int,int> decoder;
int encoder[10] = {0, 48, 109, 121, 51, 91, 95, 112, 127, 123};
void init()
{
    for(int i = 0; i < 10; i++) decoder[encoder[i]] = i;
}

int n;
vector<int> input;
bool flag[110][10];
int to_bin(string s)
{
    int ret = 0;
    for(int i = 0; i < s.length(); i++) {
        ret = ret << 1 | (s[i]=='1' ? 1 : 0);
    }
    return ret;
}

string to_str(int x)
{
    string s = "";
    while(x) {
        s = (x & 1 == 1 ? '1' : '0') + s;
        x >>= 1;
    }
    while(s.length() < 7) s = '0' + s;
    return s;
}

bool check(string input, string broken) {
    for(int i = 0; i < 7; i++) {
        if(input[i] == 1 && broken[i] == 1) return false;
    }
    return true;
}

int main(){
    init();
    int T, cas = 0;
    cin >> T;
    while(T--) {
        cin>>n;
        input.clear();
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            input.push_back(to_bin(s));
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 10; j++) flag[i][j] = false;
        //cout << "!!!! " << (91 & 123) == 91 ? 1 : 0 << endl;
        for(int i = 0; i < n; i++) {
            int x = input[i];
            //cout << "#"<< x<< endl;
            for(int j = 0; j < 10; j++) {
                int y = encoder[j];
                if((x&y)==x){
                    //cout << "##" << decoder[x] << " " << x << "-" << j << " " << y << endl;
                    flag[i][j]=true;
                }
            }
        }

        //for(int i = 0 ; i < 10; i ++) cout << flag[3][i] << endl;
        //cout << "_______________" << endl;
        vector<int> ans;
        for(int i = 0; i < 10; i++) {
            bool tmp = true;
            for(int j = 0; j < n; j++) {
                if(!flag[j][(i-j+10)%10]) {
                    tmp = false;
                    break;
                }
            }
            if(tmp) {
                ans.push_back(i);
            }
        }
        if(ans.size() != 1) {
            printf("Case #%d: ERROR!\n", ++cas);
            continue;
        }
        int broken = 0;
        bool error = false;
        for(int i = 0; i < n; i++) {
            int x = (ans[0] - i + 10) % 10;
            if(!check(to_str(input[i]), to_str(broken))) {
            //if((input[i]&broken) != 0) {
                error = true;
                break;
            }
            broken |= (encoder[x] ^ input[i]);
        }
        if(error){
            printf("Case #%d: ERROR!\n", ++cas);
            continue;
        }
        //cout << ans[0] << endl;
        //cout << to_str(broken) << endl;
        int ret = encoder[(ans[0] - n + 10) % 10] & (~broken);
        printf("Case #%d: %s\n", ++cas, to_str(ret).c_str());
    }
    return 0;
}
