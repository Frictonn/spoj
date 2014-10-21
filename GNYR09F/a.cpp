#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
state: ends with 0 or 1, adj, length
W(0, adj, len) = W(1, adj, len-1) + W(0, adj, len-1)
W(1, adj, len) = W(0, adj, len-1) + W(1, adj-1, len-1)
*/

int dp[2][103][103];

int main(){
    dp[0][0][1] = dp[1][0][1] = 1;
    dp[0][1][1] = dp[1][1][1] = 0;
    for(int k=2;k<=100;++k){
        for(int j=0;j<k;++j){
            dp[0][j][k] = dp[1][j][k-1] + dp[0][j][k-1];
            dp[1][j][k] = dp[0][j][k-1];
            if(j>0) dp[1][j][k] += dp[1][j-1][k-1];
        }
    }
    int p,tc,k,j;
    cin >> p;
    while(p--){
        cin >> tc >> k >> j;
        cout << tc << " " << (dp[0][j][k] + dp[1][j][k]) << endl;
    }
    return 0;
}