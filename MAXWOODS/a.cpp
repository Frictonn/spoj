#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

string m[203];
int dp[203][203];
int M, N;

void solve() {
    for (int i=0;i<=M;++i){
        dp[i][0] = 0;
        dp[i][N+1] = 0;
    }
    for(int i=M;i>=1;--i){
        if(i%2 == 0) {
            for(int j=1;j<=N;++j){
                if(m[i-1][j-1] == '#'){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i][j-1];
                if(i+1 <= M) dp[i][j] = max(dp[i][j], dp[i+1][j]);
                if(m[i-1][j-1] == 'T') dp[i][j]++;
            }
        } else {
            for(int j=N;j>=1;--j){
                if(m[i-1][j-1] == '#') {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i][j+1];
                if(i+1 <= M) dp[i][j] = max(dp[i][j], dp[i+1][j]);
                if(m[i-1][j-1] == 'T') dp[i][j]++;
            }
        }
    }
    /*
    for(int i=1;i<=M;++i){
        for(int j=1;j<=M;++j){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    */
    printf("%d\n", dp[1][1]);
}

int main(){
    int TC;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &M, &N);
        for(int i=0;i<M;++i){
            cin >> m[i];
        }
        solve();
    }
    return 0;
}