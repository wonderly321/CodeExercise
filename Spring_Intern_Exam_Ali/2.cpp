#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

const int mod = 10000;
int m, n, k;

int solve(int m, int x, int st){
    if(x == 0 && m == 0){
        return 1;
    }
    if(m == 0 || x == 0){
        return 0;
    }
    int ret = 0;
    for(int i = st; i <= m; i++){
        ret += solve(m-i, x-1, i);
        ret %= mod;
    }
    return ret;
}

int main() {
    while(~scanf("%d%d%d", &m, &n, &k)){
        int ret = 0;  
        for(int x = 1; x <= k-1; x ++){
            for(int y = 1; y <= k-x; y ++){
                //int z = k - x - y;
                if(x <= m && y <= n)
                    ret += solve(m, x, 1) * solve(n, y, 1);
                ret %= mod;
            }
        }
        printf("%d\n", ret);
    } 
    return 0;

}
