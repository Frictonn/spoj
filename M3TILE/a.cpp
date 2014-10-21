#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[33][3];
int N;
int main(){
    dp[0][0] = 1;
    dp[0][1] = dp[0][2] = 0;
    dp[1][0] = dp[1][2] = 0;
    dp[1][1] = 1;
    for(int k=2;k<=30;++k){
        dp[k][0] = 2*dp[k-1][1] + dp[k-2][0];
        dp[k][1] = dp[k-1][0] + dp[k-1][2];
        dp[k][2] = dp[k-1][1];
    }
    while(cin >> N, N!=-1){
        printf("%lld\n", dp[N][0]);
    }
    return 0;
}