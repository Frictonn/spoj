#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int inf = (int) 1e9;
int dp[10003];
int w[503], p[503];
int N;

int rec(int cur){
    if(cur == 0) return 0;
    if(cur < 0) return inf;
    if(dp[cur] != -1) return dp[cur];
    int ret = inf;
    for(int i=0;i<N;++i){
        ret = min(ret, p[i] + rec(cur - w[i]));
    }
    dp[cur] = ret;
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
        for(int i=0;i<=wg;++i){
            dp[i] = -1;
        }
        int ans = rec(wg);
        if(ans < inf) printf("The minimum amount of money in the piggy-bank is %d.\n", ans);
        else printf("This is impossible.\n");
    }
    return 0;
}