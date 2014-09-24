#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1003][1003];
int a[1003];

int rec(int i,int j){
    if(i > j) return 0;
    if(i == j) return a[i];
    if(dp[i][j] != -1) return dp[i][j];
    int ret1 = a[i];
    if(a[i+1] < a[j]){
        ret1 -= a[j];
        ret1 += rec(i+1,j-1);
    } else /*if(a[i+1] > a[j])*/{
        ret1 -= a[i+1];
        ret1 += rec(i+2,j);
    } /*else {
        ret1 -= a[j];
        ret1 += max(rec(i+1,j-1), rec(i+2,j));
    }*/
    int ret2 = a[j]; 
    if(a[i] < a[j-1]){
        ret2 -= a[j-1];
        ret2 += rec(i, j-2);
    } else /*if(a[i] > a[j-1])*/{
        ret2 -= a[i];
        ret2 += rec(i+1, j-1);
    }
    /*else {
        ret2 -= a[i];
        ret2 += max(rec(i+1,j-1), rec(i,j-2));
    }*/
    dp[i][j] = max(ret1, ret2);
    return dp[i][j];
}

int main(){
    int N, T=1;
    while(cin >> N, N!=0){
        for(int i=0;i<N;++i){
            cin >> a[i];
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                dp[i][j] = -1;
            }
        }
        int ans = rec(0, N-1);
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", T++, ans);
    }
    return 0;
}