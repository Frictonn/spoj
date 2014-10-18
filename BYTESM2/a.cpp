#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[103][103];
int H, W;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> H >> W;
        for(int i=0;i<H;++i){
            for(int j=0;j<W;++j){
                scanf("%d", &dp[i][j]);
            }
        }
        int ans = 0;
        for(int h=H-2;h>=0;--h){
            for(int w=0;w<W;++w){
                int tmp = dp[h+1][w];
                if(w>0) tmp = max(tmp, dp[h+1][w-1]);
                if(w+1<W) tmp = max(tmp, dp[h+1][w+1]);
                dp[h][w] += tmp;
                ans = max(dp[h][w], ans);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}