#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[2][1000003];
int c[3];
int N, M;
/*
W(p, n) = p certainly win the n game
W(p, n) = amongst {W(opp, n-1), W(opp, n-K), W(opp, n-L)}, will win if opponent can lose
Base:
W(p, 0) = 0, W(opp, 0) = 0.
*/

void solve(){
    dp[0][0] = dp[0][1] = 0;
    for(int k=1;k<=1000000;++k){
        for(int p=0;p<2;++p){
            dp[p][k] = 0;
            int op = (p+1)%2;
            for(int i=0;i<3;++i){
                int cur = k - c[i];
                if(cur < 0) continue;
                if(dp[op][cur] == 0) dp[p][k] = 1;
            }
        }
    }
}

int main(){
    c[0] = 1;
    cin >> c[1] >> c[2];
    cin >> M;
    solve();
    for(int i=0;i<M;++i){
        cin >> N;
        if(dp[0][N] == 0) printf("B");
        else printf("A");
    }
    printf("\n");
    return 0;
}