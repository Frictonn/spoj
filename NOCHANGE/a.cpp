#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>
using namespace std;

/*
If no restriction:
S(n) means n is reachable using v_1 .. v_k
S(n) = reachable if { S(n - v_i) } is reachable

n -> +v_k -> v + v_k
*/

int dp[10][100003];
int dp2[100003];
int v[10];
int sum[10];
int K, N;

bool solve(){
    for(int i=0;i<K;++i){
        for(int j=0;j<=N;++j){
            dp[i][j] = 0;
        }
    }
    dp[0][v[0]] = 1;
    for(int i=0;i<=N;++i){
        if(!dp[0][i]) continue;
        if(i + v[0] > N) continue;
        dp[0][i + v[0]] = 1+dp[0][i];
        if(i+v[0] == N) {
            return true;
        }
    }
    for(int k=1;k<K;++k){
        for(int i=0;i<=N;++i){
            if(!dp[k-1][i]) continue;
            for(int j=1;j<=dp[k-1][i];++j){
                int u = i+j*v[k];
                if(u > N) break;
                if(u == N) {
                    return true;
                }
                dp[k][u] = max(dp[k][u], j);
            }
        }
    }
    return false;
}

bool solve2(){
    sum[0] = v[0];
    for(int i=1;i<K;++i){
        sum[i] = sum[i-1] + v[i];
    }
    for(int i=0;i<=N;++i){
        dp2[i] = 0;
    }
    dp2[0] = 1;
    for(int i=0;i<=N;++i){
        if(dp2[i]) dp2[i+v[0]] = 1;
    }
    for(int k=1;k<K;++k){
        for(int i=0;i<=N;++i){
            if(!dp2[i]) continue;
            int u = i + sum[k];
            if(u>N) break;
            dp2[u] = 1;
        }
    }
    return dp2[N];
}

int main(){
    cin >> N;
    cin >> K;
    for(int i=0;i<K;++i){
        cin >> v[i];
    }
    if(solve2()) printf("YES\n");
    else printf("NO\n");
    return 0;
}