#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

/*
S(n) = max{ n, S(n/2) + S(n/3) + S(n/4) }
*/
map<int, long long> dp;

long long rec(long long n) {
    if(dp.find(n) != dp.end()) return dp[n];
    long long ret = max(n, rec(n/2) + rec(n/3) + rec(n/4));
    dp[n] = ret;
    return ret;
}

int main(){
    dp[0] = 0;
    int N;
    while(cin >> N) {
        cout << rec(N) << endl;
    }
    return 0;
}