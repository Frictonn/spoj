#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[203][203][203];
int a[204];
int N;

int rec(int dec, int inc, int idx){
    if(idx == N) {
        return 0;
    }
    if(dp[dec][inc][idx] != -1) return dp[dec][inc][idx];
    int ret = 0;
    if(a[dec] > a[idx]){
        ret = max(ret, 1 + rec(idx, inc, idx+1));
    }
    if(a[inc] < a[idx]){
        ret = max(ret, 1 + rec(dec, idx, idx+1));
    } 
    ret = max(ret, rec(dec, inc, idx+1));
    dp[dec][inc][idx] = ret;
    return ret;
}

int main(){
    while(scanf("%d", &N), N!=-1){
        for(int i=0;i<N;++i){
            scanf("%d", &a[i]);
        }
        a[N] = -1;
        a[N+1] = 1234567;
        for(int i=0;i<=N+1;++i){
            for(int j=0;j<=N+1;++j){
                for(int k=0;k<=N+1;++k){
                    dp[i][j][k] = -1;
                }
            }
        }
        printf("%d\n", N - rec(N+1, N, 0));
    }
    return 0;
}
