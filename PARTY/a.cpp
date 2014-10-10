#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
1-0 knapsack
k = 1..N
F(k, b) be the maximum amount of fun attainable with at most b budget using {1,2,..,k}
F(k, b) = max { F(k-1, b), fun[k] + F(k-1, b - cost[k]) }
F(0, 0) = 0
*/

int N, B;
int dp[503][103];
int c[103], f[103];
int maxfun, mincost;
void solve(){
    maxfun = 0;
    for(int i=0;i<=B;++i) dp[i][0] = 0;
    for(int k=1;k<=N;++k){
        for(int b=0;b<=B;++b){
            dp[b][k] = dp[b][k-1];
            if(b - c[k] >= 0) dp[b][k] = max(dp[b][k], dp[b-c[k]][k-1] + f[k]);
            if(dp[b][k] > maxfun){
                maxfun = dp[b][k];
                mincost = b;
            } else if(dp[b][k] == maxfun){
                if(mincost > b) mincost = b;
            }
        }
    }
    /*
    for(int i=0;i<=B;++i){
        for(int j=1;j<=N;++j){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    */
}

int main(){
    while(cin>>B>>N, N+B!=0){
        for(int i=1;i<=N;++i){
            cin>>c[i] >> f[i];
        }
        solve();
        cout << mincost << " " << maxfun << endl;
    }
    return 0;
}