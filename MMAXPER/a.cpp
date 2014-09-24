#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[1003][2];
int b[2];

int main(){
    int N;
    cin >> N;
    int u, v;
    cin >> u >> v;
    dp[0][0] = v;
    dp[0][1] = u;
    b[0] = u;
    b[1] = v;
    for(int i=1;i<N;++i){
        cin >> u >> v;
        dp[i][0] = max(dp[i-1][0] + abs(b[0] - u) + v, dp[i-1][1] + abs(b[1] - u) + v);
        dp[i][1] = max(dp[i-1][0] + abs(b[0] - v) + u, dp[i-1][1] + abs(b[1] - v) + u);
        b[0] = u;
        b[1] = v;
    }
    cout << max(dp[N-1][0], dp[N-1][1]) << endl;
    return 0;
}