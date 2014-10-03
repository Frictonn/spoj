#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/* PERMUT1
S(n, k) = number of permutations of [1 .. n] having exactly k permutations
S(n, k) = S(n-1, k) + S(n-1, k-1) + S(n-1, k-2) + S(n-1, k-3) + ... 

_ _ _ _ _ _
  x
eg:
                    321        123
S(3, 2) = S(2,2) + S(2, 1) + S(2, 0)
            0        1         1
*/

long long dp[15][100];

void solve() {
    for(int i=0;i<15;++i){
        for(int j=0;j<100;++j){
            dp[i][j] = 0;
        }
    }
    dp[1][0] = 1;
    for(int n=2;n<=12;++n){
        int m = (n*(n-1))/2;
        for(int k=0;k<=98 && k<=m;++k){
            for(int i=k;i>=0 && i+n-1>=k;--i){
                dp[n][k] += dp[n-1][i];
            }
        }
    }
}

int main(){
    int tc;
    cin >> tc;
    solve();
    /*
    for(int i=0;i<=12;++i){
        printf("%2d ", i);
    }
    printf("\n");
    for(int k=0;k<=98;++k){
        for(int i=0;i<=12;++i){
            printf("%2lld ", dp[i][k]);
        }
        printf("\n");
    }
    */
    while(tc--){
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
    return 0;
}