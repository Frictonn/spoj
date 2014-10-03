#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

string s;
int dp[201][201][201];
int N;

int rec(int k, int sweet, int sour){
    //printf("%d %d %d\n", k, sweet, sour);
    if(k == N) {
        if(sweet > sour) return 1;
        else return 0;
    }
    if(dp[k][sweet][sour] != -1) return dp[k][sweet][sour];
    int ret = 0;
    int csweet = sweet, csour = sour;
    if(s[k] == '1') ++csweet;
    else ++csour;
    if(csweet > csour) ret = csour + csweet + rec(k+1, 0, 0);
    ret = max(ret, rec(k+1, csweet, csour));
    ret = max(ret, rec(k+1, 0, 0));
    dp[k][sweet][sour] = ret;
    return ret;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> N;
        cin >> s;
        for(int i=0;i<=N;++i){
            for(int j=0;j<=N;++j){
                for(int k=0;k<=N;++k){
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = rec(0,0,0);
        cout << ans << endl;
    }
    return 0;
}