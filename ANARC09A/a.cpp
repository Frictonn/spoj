#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/* wrong idea */

string s;
int inf = (int) 1e9;
//int dp[2003][2003];
//int c[2003][2003];
int main(){
    int T=1;
    while(cin>>s){
        if(s == "---")break;
        int N = s.size();
        /*
        for(int i=1;i<=N;++i){
            dp[i][i-1] = 0;
        }
        for(int k=1;k<N;++k){
            if(k%2==0)continue;
            for(int i=0;i+k<N;++i){
                int j=i+k;
                if(s[i] == '{' && s[j] == '}') dp[i][j] = dp[i+1][j-1];
                else if(s[i] == '}' && s[j] == '{') dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = 1 + dp[i+1][j-1];
            }
        }
        */
        /*
        for(int k=1;k<N;++k){
            if(k%2==0)continue;
            for(int L=0;L+k<N;++L){
                int R=L+k;
                c[L][R] = inf;
                for(int i=L;i<=R;++i){
                    if( (L-i+1)%2 == 0 ){
                        c[L][R] = min(c[L][R], c[L][i] + c[i+1][R]);
                    }
                }
            }
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
        printf("%d. %d\n", T++, c[0][N-1]);
        */
    }
    return 0;
}