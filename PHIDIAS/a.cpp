#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dp[603][603];
vector<int> wd, pd;
int N, W, H;

int rec(int w, int h){
    if(dp[w][h] != -1) return dp[w][h];
    int ret = w*h;
    for(int i=0;i<N && wd[i] < w;++i){
        ret = min(ret, rec(wd[i],h) + rec(w-wd[i],h));
    }
    for(int i=0;i<N && pd[i] < h;++i){
        ret = min(ret, rec(w,pd[i]) + rec(w,h-pd[i]));
    }
    dp[w][h] = ret;
    return ret;
}

int main(){
    int TC;
    cin >> TC;
    while (TC--){
        cin >> W >> H;
        cin >> N;
        int u, v;
        for(int i=0;i<=W;++i){
            for(int j=0;j<=H;++j){
                dp[i][j] = -1;
            }
        }
        wd.clear();
        pd.clear();
        for(int i=0;i<N;++i){
            cin >> u >> v;
            wd.push_back(u);
            pd.push_back(v);
            dp[u][v] = 0;
        }
        sort(wd.begin(), wd.end());
        sort(pd.begin(), pd.end());
        int ans = rec(W,H);
        cout << ans << endl;
    }
    return 0;
}