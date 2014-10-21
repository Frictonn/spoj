#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/*
let's assume i already have array
par_item[i] => items with u != 0
attached[i][1..3] => items attached to par_item[i]
|attached|[i] => number of attachment of par_item[i]
let S(i, n, k) is the maximum v*c obtainable using par_items [1 .. i], and up 
to [1 .. k] attached of par_item[i] and n amount of space
S(i, n, k) = 
1. if k > 0
max { S(i, n-v[attached[i][k]], k-1) + v[attached[i][k]] * c[attached[i][k]]),
      S(i, n, k-1), S(i-1, n, |attached|[i-1]) }
2. if k == 0
max { S(i-1, n-v[i], |attached|[i-1]) + v[i]*c[i],
      S(i-1, n, |attached|[i-1]) }
*/

int N, V;
int dp[63][32003];
int par[63], par_addr[63], par_item[63], attached[63][3], deg[63];
int v[63], c[63];

int main(){
    int tc;
    int u;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &V, &N);
        int idx = 1;
        for(int i=0;i<=N;++i) deg[i] = 0;
        for(int i=1;i<=N;++i){
            scanf("%d %d %d", &v[i], &c[i], &par[i]);
        }
        for(int i=1;i<=N;++i){
            if(par[i] == 0){
                par_item[idx] = i;
                par_addr[i] = idx;
                ++idx;
            }
        }
        for(int i=1;i<=N;++i){
            if(par[i] != 0){
                int index = par_addr[par[i]];
                attached[index][deg[index]++] = i;
            }
        }
        for(int i=0;i<=idx;++i){
            dp[i][0] = 0;
        }
        int cost, val, cur, Z;
        for(int i=1;i<idx;++i){
            for(int n=1;n<=V;++n){        
                cur = par_item[i];
                dp[i][n] = dp[i-1][n];
                if(n - v[cur] < 0) continue;
                Z = 1 << deg[i];
                
                for(int bit = 0; bit < Z; ++bit){
                    cost = v[cur];
                    val = c[cur] * v[cur];
                    
                    for(int j=0;j<deg[i];++j){
                        if(bit & (1<<j)){
                            cost += v[attached[i][j]];
                            val += v[attached[i][j]] * c[attached[i][j]];
                        }
                    }
                    if(n - cost >=0){
                        dp[i][n] = max(dp[i][n], dp[i-1][n-cost] + val);
                    }
                }
            }
        }
        
        printf("%d\n", dp[idx-1][V]);
    }
    return 0;
}