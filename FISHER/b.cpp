#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int inf = (int) 1e9;
int t, N;
int cc[53][53], tt[53][53];
int dp[53][1005];

/* DP on TIME (level) wow! since t < 1000
S(v, t) be the minimum cost for reaching v from 0 with time less than or equal to t.
S(v, 0) = INF for all v != 0, OR 0 for v == 0.
S(v, t) = min( S(v, t-1), S(i, t - time[i][v]) + cost[i][v] )
*/

int main(){
    while(cin >> N >> t, N+t!=0){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cin >> tt[i][j];
            }
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cin >> cc[i][j];
            }
        }
        dp[0][0] = 0;
        for(int i=1;i<=N;++i){
            dp[i][0] = inf;
        }
        int lt = -1;
        for(int k=1;k<=t;++k){
            for(int i=0;i<N;++i){
                dp[i][k] = dp[i][k-1];
                for(int j=0;j<N;++j){
                    if(k < tt[j][i]) continue;
                    dp[i][k] = min(dp[i][k], dp[j][k-tt[j][i]] + cc[j][i]);
                }
            }
            if(dp[N-1][k] != dp[N-1][k-1]){
                lt = k;
            }
        }
        cout << dp[N-1][lt] << " " << lt << endl;
    }
    return 0;
}