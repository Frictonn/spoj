#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
W(sum, k) be the number of ways to group [1..k] such that
the sum of the last group is at most |sum|
W(sum, k) = sum [i = k..1] W(sum_from[i][k], i)
base:
W(sum, 0) = 1
*/

string str;
int N;
int a[30];
int sum[30];
long long dp[260][30];

int main(){
    int tc = 1;
    while(cin>>str){
        if(str == "bye") break;
        N = str.size();
        sum[0] = 0;
        for(int i=1;i<=N;++i){
            a[i] = str[i-1]-'0';
            sum[i] = a[i] + sum[i-1];
        }
        for(int i=0;i<=sum[N];++i){
            dp[i][0] = 1;
        }
        for(int k=1;k<=N;++k){
            for(int s=0;s<=sum[N];++s){
                dp[s][k] = 0;
                for(int i=k;i>=1;--i){
                    int cur = sum[k] - sum[i-1];
                    if(s < cur) break;
                    dp[s][k] += dp[cur][i-1];
                }
            }
        }
        /*
        for(int k=1;k<=sum[N];++k){
            for(int i=1;i<=N;++i){
                printf("%lld ", dp[k][i]);
            }
            printf("\n");
        }
        */
        printf("%d. %lld\n", tc++, dp[sum[N]][N]);
    }
    return 0;
}