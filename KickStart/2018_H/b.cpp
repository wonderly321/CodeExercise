#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 5000002;
int n;
string s;
int a[maxn];

int main()
{
    int T, cas = 0;
    cin >> T;
    while(T--) {
        cin >> n;
        cin >> s;
        for(int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
        }

        int l = n - (n >> 1);
        long long sum = 0;
        long long ans = 0;
        for(int i = 0; i < l; i++) sum += a[i];
        ans = max(ans, sum);
        for(int i = l, j = 0; i < n; i++, j++) {
            sum = sum + a[i] - a[j];
            ans = max(ans, sum);
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}
