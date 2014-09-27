#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[2003], b[2003];
int dp[2003][2003];

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n=0,m=0;
        while(cin >> a[n]){
            if(a[n] == 0) break;
            ++n;
        }
        int ans = 0;
        while(cin >> b[0]){
            if(b[0] == 0) break;
            m = 1;
            while(cin >> b[m]){
                if(b[m] == 0) break;
                ++m;
            }
            for(int i=0;i<=n;++i){
                dp[i][0] = 0;
            }
            for(int i=0;i<=m;++i){
                dp[0][i] = 0;
            }
            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                    dp[i][j] = (a[i-1] == b[j-1]) ? 1+dp[i-1][j-1] : 0;
                    dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
                }
            }
            ans = max(dp[n][m], ans);
        }
        cout << ans << endl;
    }
    return 0;
}