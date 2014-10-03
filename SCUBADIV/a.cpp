#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int INF = (int) 1e9;
int ans;
int a[1003][3], dp[51][161];
int N, t, aa;

int solve(){
    ans = INF;
    for(int i=0;i<=50;++i){
        for(int j=0;j<=160;++j){
            if(i == 0 && j == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = INF;
            /*
            if(i>0) dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(j>0) dp[i][j] = min(dp[i][j], dp[i][j-1]);
            */
            for(int k=0;k<N;++k){
                if(i - a[k][0] >= 0 && j - a[k][1] >= 0){
                    dp[i][j] = min(dp[i][j], a[k][2] + dp[i-a[k][0]][j-a[k][1]]);
                }
            }
            if(i >= t && j >= aa) ans = min(dp[i][j], ans);
        }
    }
}

int solve2(){
    for(int i=0;i<=50;++i){
        for(int j=0;j<=160;++j){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int k=0;k<N;++k){
        for(int i=50;i>=a[k][0];--i){
            for(int j=160;j>=a[k][1];--j){
                //if(i - a[k][0] >= 0 && j - a[k][1] >= 0){
                    dp[i][j] = min(dp[i][j], a[k][2] + dp[i-a[k][0]][j-a[k][1]]);
                //}
            }
        }
    }
    ans = INF;
    for(int i=0;i<=50;++i){
        for(int j=0;j<=160;++j){
            if(i >= t && j >= aa) ans = min(dp[i][j], ans);
        }
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> t >> aa;
        cin >> N;
        for(int i=0;i<N;++i){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        solve2();
        /*
        for(int i=0;i<=2*t;++i){
            for(int j=0;j<=2*aa;++j){
                if(dp[i][j] == INF) printf("  x");
                else printf("%3d", dp[i][j]);
            }
            printf("\n");
        }
        */
        cout << ans << endl;
    }
    return 0;
}