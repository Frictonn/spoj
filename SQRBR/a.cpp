#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int op[43];
int dp[43][43];
int n;

int rec(int k, int open){
    //printf("%d %d\n", k, open);
    if(k == 2*n){
        if (open == 1 && !op[k]) return 1;
        else return 0;
    }
    if(dp[k][open] != -1) return dp[k][open];
    if(op[k]){
        return rec(k+1, open+1);
    } else {
        dp[k][open] = rec(k+1, open+1);
        if(open > 0) dp[k][open] += rec(k+1,open-1);
        return dp[k][open];
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int k;
        cin >> n >> k;
        for(int i=0;i<=2*n;++i) op[i] = 0;
        for(int i=0;i<k;++i){
            int u;
            cin >> u;
            op[u] = 1;
        }
        for(int i=0;i<=2*n;++i){
            for(int j=0;j<=2*n;++j){
                dp[i][j] = -1;
            }
        }
        int ans = rec(1, 0);
        cout << ans << endl;
    }
    return 0;
}