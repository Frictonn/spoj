#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int dp[1003][1003];
string a, b;
int K, A, B;

int rec(int i, int j){
    if(i == A || j == B) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int k = 0;
    int ret = 0;
    //try match
    for(; i+k < A && j+k < B; ++k){
        if(a[i+k] != b[j+k]) break;
    }
    if(k >= K) {
        
        for(int t=K; t<=k; ++t){
            ret = max(ret, t + rec(i+t, j+t));
        }
        //ret = max(ret, k + rec(i+k, j+k));
    }
    ret = max(ret, rec(i+1,j));
    ret = max(ret, rec(i,j+1));
    dp[i][j] = ret;
    return ret;
}

int main(){
    while(cin >> K){
        if(K == 0) break;
        cin >> a >> b;
        A = a.size();
        B = b.size();
        for(int i=0;i<A;++i){
            for(int j=0;j<B;++j){
                dp[i][j] = -1;
            }
        }
        int ans = rec(0,0);
        cout << ans << endl;
    }
    return 0;
}
