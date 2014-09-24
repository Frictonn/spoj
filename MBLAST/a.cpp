#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int inf=(int)1e9;
int dp[2003][2003];
string a,b;
int K;

int main(){
    cin >> a >> b;
    cin >> K;
    int A = a.size(), B = b.size();
    for(int i=0;i<=A;++i){
        dp[i][0] = K*i;
    }
    for(int j=0;j<=B;++j){
        dp[0][j] = K*j;
    }
    for(int i=1;i<=A;++i){
        for(int j=1;j<=B;++j){
            dp[i][j] = inf;
            dp[i][j] = min(dp[i][j], dp[i-1][j] + K);
            dp[i][j] = min(dp[i][j], dp[i][j-1] + K);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs((int)a[i-1] - b[j-1]));
        }
    }
    /*
    for(int i=0;i<=A;++i){
        for(int j=0;j<=B;++j){
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }
    */
    
    cout << dp[A][B] << endl;
    return 0;
}