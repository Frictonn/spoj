#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

/*
s1 s2 s3 ... sn-1 sn
v1 v2 ...    vn-1 vn

S([sn] againts [vn]) = min of:
if use sn:
1 + S([sn-1] againts [{match of sn in v} - 1])
if not use s1:
S([sn-1] againts [vn])

s against empty = 1
empty againts s = inf
*/

int INF = (int) 1e9;
string s, v;
int N, M;
int next[1003][1003], dp[1003][1003];
int main(){
    cin >> s >> v;
    N = s.size();
    M = v.size();
    for(int i=0;i<N;++i){
        int prev = -1;
        for(int j=0;j<M;++j){
            if(s[i] == v[j]) prev = j;
            next[i+1][j+1] = prev;
        }
    }
    /*
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            printf("%d ", next[i+1][j+1]);
        }
        printf("\n");
    }
    */
    for(int i=1;i<=N;++i){
        dp[i][0] = 1;
    }
    for(int i=0;i<=M;++i){
        dp[0][i] = INF;
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(next[i][j] == -1) dp[i][j] = 1;
            else {
                dp[i][j] = min(1+dp[i-1][next[i][j]], dp[i-1][j]);
            }
        }
    }
    /*
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(dp[i][j] != INF) printf("%d ", dp[i][j]);
            else printf("x ");
        }
        printf("\n");
    }
    */
    printf("%d\n", dp[N][M]);
    return 0;
}
