#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long INF = (long long) 1e18;
long long dp[103][103];
long long a[103];
long long sum[103];
int N;

int num(int i, int j){
    int ret = sum[j];
    if(i>0) ret -= sum[i-1];
    if(ret<0) ret += 100;
    return ret;
}

void solve(){
    for(int i=0;i<N;++i){
        dp[i][i] = 0;
    }
    for(int k=1;k<=N-1;++k){
        for(int i=0;i+k<N;++i){
            int j = i+k;
            dp[i][j] = INF;
            for(int t=i;t<=j-1;++t){
                dp[i][j] = min(dp[i][j], dp[i][t] + dp[t+1][j] + num(i, t) * num(t+1, j));
            }
        }
    }
    cout << dp[0][N-1] << endl;
}

int main(){
    while(cin >> N){
        for(int i=0;i<N;++i){
            cin >> a[i];
            sum[i] = a[i];
            if(i>0) sum[i] += sum[i-1];
            sum[i] %= 100;
        }
        solve();
    }
    return 0;
}