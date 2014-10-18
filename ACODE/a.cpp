#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[5005];
long long dp[5005];
int N;

int main(){
    while(scanf("%s", s)){
        if(s[0] == '0') break;
        N = strlen(s);
        dp[N] = 1;
        if(s[N-1] == '0') dp[N-1] = 0;
        else dp[N-1] = 1;
        for(int n=N-2;n>=0;--n){
            if(s[n] == '0'){
                dp[n] = 0;
                continue;
            }
            long long tmp = dp[n+1];
            if(s[n] == '1'){
                tmp += dp[n+2];
            }
            if(s[n] == '2' && s[n+1] - '0' <= 6){
                tmp += dp[n+2];
            }
            dp[n] = tmp;
        }
        printf("%lld\n", dp[0]);
    }
    return 0;
}