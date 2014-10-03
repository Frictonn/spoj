#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[70][11];

int main(){
    for(int i=0;i<=9;++i){
        dp[0][i] = 1;
    }
    for(int i=1;i<=64;++i){
        for(int j=9;j>=0;--j){
            dp[i][j] = 0;
            for(int k=j;k<=9;++k){
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    int tc, num, v;
    cin >> tc;
    while(tc--){
        cin >> num;
        cin >> v;
        long long ans = 0;
        for(int i=0;i<=9;++i){
            ans += dp[v-1][i];
        }
        cout << num << " " << ans << endl;
    }
    return 0;
}