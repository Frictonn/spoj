#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int a[12];
int dp[12];
int N;

int main(){
    cin >> N;
    for(int i=0;i<N;++i){
        cin >> a[i];
    }
    int ans = 1;
    for(int i=0;i<N;++i){
        dp[i] = 1;
        for(int j=i-1;j>=0;--j){
            if(a[j] < a[i]) dp[i] = max(dp[i], 1 + dp[j]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}