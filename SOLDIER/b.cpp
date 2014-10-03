#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int dp[7][1005];
int p[7][103], q[7][103], n[7];
/* S(k, c) is the maximum quality using gained after buying k items using cost less or equal to c 
S(k, c) = max { min(q[k][i], S(k-1, c-p[k][i])) , S(k, c-1) }
*/
int main(){
    int N, t;
    cin >> N >> t;
    for(int i=0;i<7;++i){
        n[i] = 0;
        for(int j=0;j<1005;++j){
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<N;++i){
        int u,v,w;
        cin >> u >> v >> w;
        p[u][n[u]] = v;
        q[u][n[u]] = w;
        n[u]++;
    }
    for(int i=0;i<=t;++i){
        dp[0][i] = (int) 1e9;
    }
    for(int k = 1; k <= 6; ++k){
        for(int c = 1; c<=t; ++c){
            dp[k][c] = dp[k][c-1];
            for(int i=0;i<n[k];++i){
                if( c - p[k][i] < 0 ) continue;
                dp[k][c] = max(dp[k][c], min(q[k][i], dp[k-1][c - p[k][i]]));
            }
        }
    }
    cout << dp[6][t] << endl;
    return 0;
}