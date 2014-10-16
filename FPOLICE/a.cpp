#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
int inf = (int) 1e9;

pair<int,int> dp[103][253];   //minimum risk and minimum length to reach N using at most T
int dist[103][103];
int risk[103][103];
int T, N;
void solve(){
    for(int i=0;i<N;++i){
        dp[i][0] = make_pair(inf,inf);
    }
    dp[0][0] = make_pair(0, 0);
    for(int t=1;t<=T;++t){
        for(int n=0;n<N;++n){
            dp[n][t] = dp[n][t-1];
            for(int m=0;m<N;++m){
                if(m==n) continue;
                if(t-dist[m][n] < 0) continue;
                int cur = dp[m][t-dist[m][n]].first + risk[m][n];
                int curd = dp[m][t-dist[m][n]].second + dist[m][n];
                if(dp[n][t].first > cur){
                    dp[n][t].first = cur;
                    dp[n][t].second = curd;
                } else if(dp[n][t].first == cur){
                    dp[n][t].second = min(dp[n][t].second, curd);
                }
            }
        }
    }
    if(dp[N-1][T].first < inf) {
        printf("%d %d\n", dp[N-1][T].first, dp[N-1][T].second);
    } else {
        printf("-1\n");
    }
    return;
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &N);
        scanf("%d", &T);
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                scanf("%d", &dist[i][j]);
            }
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                scanf("%d", &risk[i][j]);
            }
        }
        solve();
    }
    return 0;
}