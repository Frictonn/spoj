#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

long long mod = (int) 1e9  + 7;
long long dp[26];
string s;

int solve(){
    int len = s.size();
    for(int i=0;i<26;++i){
        dp[i] = 0;
    }
    long long sum = 0;
    for(int i=1;i<=len;++i){
        int cur = s[i-1] - 'A';
        long long newsum = (sum*2LL + 1LL - dp[cur])%mod;
        if(newsum < 0) newsum = mod + newsum;
        dp[cur] = (sum+1)%mod;
        sum = newsum;
    }
    sum = (sum+1)%mod;
    cout << sum << endl;
}

int main(){
    int tc;
    cin >> tc;
    getchar();
    while(tc--){
        getline(cin, s);
        solve();
    }
    return 0;
}