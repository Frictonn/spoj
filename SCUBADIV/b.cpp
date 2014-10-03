#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int INF = 123456789;
int a[1001][3];
int dp[1001][22][80];
int N;
int T, A;

int solve() {
    for(int k=0;k<=N;++k){
        for(int i=0;i<=21;++i){
            for(int j=0;j<=79;++j){
                if(k==0) {
                    dp[k][i][j] = INF;
                    if(i==0 && j==0) dp[k][i][j] = 0;
                } else {
                    dp[k][i][j] = min(dp[k-1][i][j], a[k][2] + dp[k-1][max(0,i-a[k][0])][max(0,j-a[k][1])]);
                }
            }
        }
    }
    return dp[N][T][A];
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> T >> A;
        cin >> N;
        for(int i=1;i<=N;++i){
            cin>>a[i][0] >> a[i][1] >> a[i][2];
        }
        int ans = solve();
        cout << ans << endl;
    }
    return 0;
}