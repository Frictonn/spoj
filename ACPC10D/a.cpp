#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/* There is some partial ordering in a sense that if v -> u, u cannot point to v and any
other ancestor of v */
int inf = (int) 1e9;
int p[200003][3];
int dp[200003][3];
int N;

int rec(int k, int col){
    if(k == N-1){
        if(col == 1) return p[k][col];
        if(col == 0) return p[k][col] + p[k][col+1];
        if(col == 2) return inf;
    }
    if(dp[k][col] != -inf) return dp[k][col];
    int ret = inf;
    if(col+1 < 3){
        ret = min(ret, rec(k,col+1));
        ret = min(ret, rec(k+1,col+1));
    }
    if(col-1 >= 0){
        ret = min(ret, rec(k+1,col-1));
    }
    ret = min(ret, rec(k+1, col));
    dp[k][col] = p[k][col] + ret;
    return dp[k][col];
}

int main(){
    int T=1;
    while(cin >> N, N!=0){
        for(int i=0;i<N;++i){
            for(int j=0;j<3;++j){
                cin >> p[i][j];
            }
        }
        for(int i=0;i<3;++i){
            dp[N-1][i] = p[N-1][i];
        }
        dp[N-1][0] += p[N-1][1];
        dp[N-2][2] = p[N-1][1] + p[N-2][2];
        dp[N-2][1] = p[N-2][1] + min(dp[N-1][0], min(dp[N-1][1], dp[N-2][2]));
        for(int i=(N-2)*3;i>=1;--i){
            int k = i/3;
            int col = i%3;
            dp[k][col] = dp[k+1][col];
            if(col+1 < 3){
                dp[k][col] = min(dp[k][col], min(dp[k][col+1], dp[k+1][col+1]));
            }
            if(col-1 >= 0){
                dp[k][col] = min(dp[k][col], dp[k+1][col-1]);
            }
            dp[k][col] += p[k][col];
        }
        /*
        for(int i=0;i<N;++i){
            for(int j=0;j<3;++j){
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        */
        //int ans = rec(0, 1);
        printf("%d. %d\n", T++, dp[0][1]);
    }
    return 0;
}