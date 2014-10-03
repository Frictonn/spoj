#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long v[2003];
long long dp[2003][2003];
int N;

long long solve(){
    for(int i=0;i<N;++i){
        dp[i][i] = N * v[i];
    }
    for(int k=1;k<N;++k){
        for(int i=0;i+k<N;++i){
            int j = i+k;
            long long a = i+(N-1-j) + 1;
            dp[i][j] = max(a * v[i] + dp[i+1][j], a * v[j] + dp[i][j-1]);
        }
    }
    return dp[0][N-1];
}

int main(){
    cin >> N;
    for(int i=0;i<N;++i){
        cin >> v[i];
    }
    cout << solve() << endl;
    return 0;
}