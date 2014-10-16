#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

/* Idea 1: top down */
/* segmentation fault since recursion is too deep */

int box[33][3];
int dp[33][3][2];
int N;

int rec(int k, int state, int turn){
    printf("%d %d %d\n", k, state, turn);
    if(dp[k][state][turn] != -1) return dp[k][state][turn];
    int bh = box[k][state];
    int bw = box[k][(state+1)%3];
    if(turn) swap(bh, bw);
    int H = box[k][(state+2)%3];
    int ret = 0;
    for(int i=0;i<N;++i){
        for(int m=0;m<3;++m){
            for(int n=0;n<2;++n){
                int cur_bh = box[i][state];
                int cur_bw = box[i][(state+1)%3];
                if(n) swap(cur_bh, cur_bw);
                if(bh > cur_bh && bw > cur_bw) { // check PS again
                    ret = max(ret, rec(i, m, n));
                }
            }
        }
    }
    dp[k][state][turn] = ret + H;
    return ret + H;
}

int main(){
    while(cin >> N){
        if(N==0)break;
        for(int i=0;i<N;++i){
            for(int j=0;j<3;++j){
                scanf("%d", &box[i][j]);
            }
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<3;++j){
                for(int k=0;k<2;++k){
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<N;++i){
            for(int j=0;j<3;++j){
                ans = max(ans, max(rec(i,j,0), rec(i,j,1)));
            }
        }
        cout << ans << endl;
    }
    return 0;
}