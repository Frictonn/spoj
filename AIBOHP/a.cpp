#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
#define NMAX 8000
string s;
short dp[6101][6101];

int rec(int L, int R){
    if(L >= R) return 0;
    if(dp[L][R] != -1) return dp[L][R];
    int ret = NMAX;
    if(s[L] == s[R]) ret = min(ret, rec(L+1, R-1));
    ret = min(ret, 1 + rec(L+1,R));
    ret = min(ret, 1 + rec(L,R-1));
    dp[L][R] = ret;
    return ret;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        int N = s.size();
        for(int i=0;i<N;++i){
            for(int j=i;j<N;++j){
                dp[i][j] = -1;
            }
        }
        int ans = rec(0, N-1);
        cout << ans << endl;
    }
    return 0;
}