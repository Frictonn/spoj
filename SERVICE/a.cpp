#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

/*
S(a, b, i) = cost to handle request [i+1 .. N] with a, b, and item[i]
O(N*M*M)
*/
int INF = (int) 1e8;
int dp[203][203][2];
int cost[203][203];
int town[1003];
int N, M;

void solve() {
    int s = (N-2)%2;
    for(int i=0;i<M;++i){
        for(int j=0;j<M;++j){
            dp[i][j][s] = INF;
            if(i == j || i == town[N-2] || j==town[N-2]) {
                //printf("x ");
                continue;
            }
            if(j!=town[N-1] && town[N-2]!=town[N-1]) dp[i][j][s] = cost[i][town[N-1]];
            if(i!=town[N-1] && town[N-2]!=town[N-1]) dp[i][j][s] = min(dp[i][j][s], cost[j][town[N-1]]);
            if(i!=town[N-1] && j!=town[N-1]) dp[i][j][s] = min(dp[i][j][s], cost[town[N-2]][town[N-1]]);
            //printf("%d ", dp[i][j][s]);
        }
        //printf("\n");
    }
    for(int k=N-3;k>=0;--k){
        int cur = k%2;
        //printf("k=%d\n", k);
        for(int i=0;i<M;++i){
            for(int j=0;j<M;++j){
                if(i==j || i == town[k] || j == town[k]){
                    dp[i][j][cur] = INF;
                    //printf("x ");
                    continue;
                }
                dp[i][j][cur] = min(cost[i][town[k+1]] + dp[j][town[k]][cur^1], min(cost[j][town[k+1]] + dp[i][town[k]][cur^1], cost[town[k]][town[k+1]] + dp[i][j][cur^1]));
                //printf("%d ", dp[i][j][cur]);
            }
            //printf("\n");
        }
    }
    int ans = min(cost[0][town[0]] + dp[1][2][0], min(cost[1][town[0]] + dp[0][2][0], cost[2][town[0]] + dp[0][1][0]));
    printf("%d\n", ans);
}


int main(){
    int tc;
    cin >> tc;
    while(tc--){
        scanf("%d %d", &M, &N);
        for(int i=0;i<M;++i){
            for(int j=0;j<M;++j){
                scanf("%d", &cost[i][j]);
            }
        }
        for(int i=0;i<N;++i){
            scanf("%d", &town[i]);
            --town[i];
        }
        solve();
    }
    return 0;
}