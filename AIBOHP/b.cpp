#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define NMAX 6102

int dp[NMAX][NMAX];
char s[NMAX];

int main(){
    int t;
    cin >> t;
    for(int i=0;i<NMAX;++i){
        dp[i][i] = 1;
        if(i) dp[i][i-1] = 0;
    }
    while(t--){
        scanf(" %s", s);
        int N = strlen(s);
        for(int j=1;j<N;++j){   // j=length-1 of the string
            for(int i=0;i+j<N;++i){   // starting index
                dp[i][j] = 1 + min(dp[i+1][j-1], dp[i][j-1]);
                if(s[i] == s[i+j]) dp[i][j] = min(dp[i][j], dp[i+1][j-2]);
            }
        }
        cout << dp[0][N-1] << endl;
    }
    return 0;
}