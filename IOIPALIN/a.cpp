#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 31234
char s[5003];
short dp[5003][5003];
short N;

int main() {
    cin >> N;
    scanf("%s", s);
    for(short i=0;i<=N;++i){
        dp[i][i] = 0;
        if(i>0) dp[i][i-1] = 0;
    }
    for(short k=1;k<N;++k){
        for(short i=1;i+k<=N;++i){
            short j=i+k;
            if(s[i-1] == s[j-1]) dp[i][j] = dp[i+1][j-1];
            else dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
        }
    }
    printf("%d\n", dp[1][N]);
    return 0;
}