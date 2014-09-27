#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N,M,X,Y,P[23][23];
int dp[23][23];

int main(){
    cin>>N>>M;
    cin >> X>>Y;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin >> P[i][j];
        }
    }
    dp[N][M] = P[N][M];
    for(int i=N-1;i>=1;--i){
        dp[i][M] = dp[i+1][M] + P[i][M];
    }
    for(int i=M-1;i>=1;--i){
        dp[N][i] = dp[N][i+1] + P[N][i];
    }
    for(int i=N-1;i>=1;--i){
        for(int j=M-1;j>=1;--j){
            dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
            dp[i][j] += P[i][j];
        }
    }
    /*
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    */
    int ans = 2*P[X][Y] - dp[X][Y];
    if(ans < 0) printf("N\n");
    else printf("Y %d\n", ans);
    return 0;
}