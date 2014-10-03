#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
#define INF 123456
string a, b;
int A, B;
int dp[2003][2003];

int solve(){
    A = a.size();
    B = b.size();
    for(int i=0;i<=A;++i){
        dp[i][0] = i;
    }
    for(int j=0;j<=B;++j){
        dp[0][j] = j;
    }
    for(int i=1;i<=A;++i){
        for(int j=1;j<=B;++j){
            dp[i][j] = INF;
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            dp[i][j] = min(min(1+dp[i-1][j-1], dp[i][j]), 1+min(dp[i-1][j], dp[i][j-1]));
        }
    }
    /*
    for(int i=0;i<=A;++i){
        for(int j=0;j<=B;++j){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    */
    return dp[A][B];
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        cout << solve() << endl;
    }
    return 0;
}