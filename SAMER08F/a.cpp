#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[103];

int main(){
    dp[0] = 0;
    for(int i=1;i<=100;++i){
        dp[i] = dp[i-1] + i*i;
    }
    int n;
    while(cin>>n, n!=0){
        cout << dp[n] << endl;
    }
    return 0;
}