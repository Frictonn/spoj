#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[504][504];
int s[504][504];
int R, C;
void solve(){
    for(int i=0;i<=R+1;++i){
        dp[i][C+1] = 12345678;
    }
    for(int i=0;i<=C+1;++i){
        dp[R+1][i] = 12345678;
    }
    for(int j=C;j>=1;--j){
        for(int i=R;i>=1;--i){
            if(i==R && j==C) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - s[i][j]);
        }
    }
    printf("%d\n", dp[1][1]);
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &R, &C);
        for(int i=1;i<=R;++i){
            for(int j=1;j<=C;++j){
                scanf("%d", &s[i][j]);
            }
        }
        solve();
    }
    return 0;
}