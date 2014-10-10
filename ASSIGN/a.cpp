#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
S(k, bm) be the number of ways to distribute to 1..k given bitmask bm
*/

/* TIME LIMIT EXCEEDED */

/* 
dp table overestimate.
k is not needed, since the number of ON bits equals to k.
so dp[1050000] is enough.
*/

/*
have to use bottom up to pass
*/

//long long dp[20][1050000];
long long dp[1050000];
int like[20][20];
int N;

/*
long long rec(int k, int bm){
    if(k == N) return 1;
    if(dp[k][bm] != -1) return dp[k][bm];
    long long ret = 0;
    for(int i=0;i<N;++i){
        if( (bm & (1<<i)) || !like[k][i]) continue;
        ret += rec(k+1, bm | (1<<i));
    }
    dp[k][bm] = ret;
    return ret;
}
*/

long long rec(int k, int bm){
    if(k == N) return 1;
    if(dp[bm] != -1) return dp[bm];
    long long ret = 0;
    for(int i=0;i<N;++i){
        if( (bm & (1<<i)) || !like[k][i] ) continue;
        ret += rec(k+1, bm | (1 << i));
    }
    dp[bm] = ret;
    return ret;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> N;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                scanf("%d", &like[i][j]);
            }
        }
        /*
        for(int i=0;i<N;++i){
            for(int j=0;j<(1<<N);++j){
                dp[i][j] = -1;
            }
        }
        */
        for(int i=0;i<(1<<N);++i){
            dp[i] = -1;
        }
        cout << rec(0, 0) << endl;
    }
    return 0;
}