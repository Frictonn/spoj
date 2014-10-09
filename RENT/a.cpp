#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
using namespace std;

vector<map<int, int> > m;
map<int, int>::iterator it;
int dp[1000003];
int N;
/*
int rec(int k) {
    cout << k << endl;
    if(k > 1000000) return 0;
    if(dp[k] != -1) return dp[k];
    int ret = 0;
    if(m[k].empty()) {
        return rec(k+1);
    }
    for(it = m[k].begin(); it != m[k].end(); ++it) {
        ret = max(ret, rec(k + it->first) + it->second);
    }
    dp[k] = ret;
    return ret;
}
*/
int main() {
    int tc;
    cin >> tc;
    while(tc--){
        m = vector<map<int,int> >(1000003);
        int u,v,w;
        int N;
        scanf("%d", &N);
        for(int i=0;i<N;++i){
            scanf("%d %d %d", &u, &v, &w);
            m[u][v] = max(m[u][v], w);
        }
        //int ans = rec(0);
        dp[1000000] = 0;
        for(int k=999999;k>=0;--k){
            dp[k] = dp[k+1];
            for(it = m[k].begin(); it != m[k].end(); ++it) {
                dp[k] = max(dp[min(1000000,k+it->first)] + it->second, dp[k]);
            }
        }
        /*
        for(int i = 0; i<=10; ++i){
            printf("%d ", dp[i]);
        }
        printf("\n");
        */
        printf("%d\n", dp[0]);
        //cout << ans << endl;
    }
    return 0;
}