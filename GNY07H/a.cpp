#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
0     1     2     3     4
2112, 1122, 1221, 2211, 2222
A     B     C     D     E
*/

long long dp[1000000][5];
int N;

long long rec(int n, int type) {
    if (dp[n][type] != -1) return dp[n][type];
    long long ret = 0;
    if (type == 4) {
        ret = rec(n-1, 2) + rec(n-2, 4) + rec(n-1, 4) + rec(n-1, 3) + rec(n-1, 1);
    } else if (type == 0) {
        ret = rec(n-1, 2);
    } else if (type == 1) {
        ret = rec(n-1, 4) + rec(n-1, 3);
    } else if (type == 2) {
        ret = rec(n-1, 4) + rec(n-1, 0);
    } else if (type == 3) {
        ret = rec(n-1, 4) + rec(n-1, 1);
    }
    dp[n][type] = ret;
    return ret;
}

int main() {
    int tc, tt=1;
    cin >> tc;
    for (int i=0;i<1000000;++i) {
        for (int j=0;j<5;++j) {
            dp[i][j] = -1;
        }
    }
    for (int i=0;i<5;++i){
        dp[0][i] = 0;
        dp[1][i] = 0;
    }
    dp[1][4] = 1;
    dp[2][0] = 1;
    dp[2][1] = 2;
    dp[2][2] = 1;
    dp[2][3] = 2;
    dp[2][4] = 5;
    while(tc--) {
        cin >> N;
        long long ans = rec(N,4);
        printf("%d %lld\n", tt++, ans);
    }
    return 0;
}