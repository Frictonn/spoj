#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long a[100020];
int N;
long long dp[100003];

void solve(){
    for(int i=0;i<=6;++i){
        dp[N+i] = 0;
    }
    for(int i=N-1;i>=0;--i){
        dp[i] = a[i] + dp[i+2];
        if(i+1 < N){
            dp[i] = max(dp[i], a[i] + a[i+1] + dp[i+4]);
        }
        if(i+2 < N) { 
            dp[i] = max(dp[i], a[i] + a[i+1] + a[i+2] + dp[i+6]);
        }
    }
    cout << dp[0] << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        scanf("%d", &N);
        for(int i=0;i<N;++i){
            scanf("%lld", &a[i]);
        }
        solve();
    }
    return 0;
}