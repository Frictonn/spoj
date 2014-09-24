#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int inf = (int) 1e9;
int dp[503][10003];
int w[503], p[503];
int N;

/*TIME LIMIT EXCEEDED*/
int rec(int cur, int k){
    if(cur == 0) return 0;
    if(k == N) return inf;
    if(dp[k][cur] != -1) return dp[k][cur];
    int ret = inf;
    for(int i=0;i*w[k]<=cur;++i){
        ret = min(ret, i*p[k] + rec(cur - i*w[k], k+1));
    }
    dp[k][cur] = ret;
    return ret;
}


int main(){
    int TC, E, F, wg;
    cin >> TC;
    while(TC--){
        cin >> E >> F;
        wg = F-E;
        cin >> N;
        for(int i=0;i<N;++i){
            cin >> p[i] >> w[i];
        }
        for(int i=0;i<=N;++i){
            for(int j=0;j<=wg;++j){
                dp[i][j] = -1;
            }
        }
        int ans = rec(wg, 0);
        if(ans < inf) printf("The minimum amount of money in the piggy-bank is %d.\n", ans);
        else printf("This is impossible.\n");
    }
    return 0;
}