#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

/*
Let S(k, open) be the number of min operations to balance the string
with |open| open brackets by the time we start at k.
Let current bracket be cur. We have several cases:
1. open is 0, and cur = '}', then we have to flip.
   S(k, open) = 1 + S(k+1, open+1)
   open is 0 and cur = '{', then we cannot flip.
   S(k, open) = S(k+1, open+1)
2. open > 0 and cur = '}'. We can use cur to close an open bracket, or
   flip it to add new open brackets.
   S(k, open) = min( S(k+1, open-1), 1 + S(k+1, open+1) )
3. open > 0 and cur = '{', then we have
   S(k, open) = min( S(k+1, open+1), 1 + S(k+1, open-1) )
*/
int inf = (int) 1e9;
string s;
int dp[2003][2003];


int main(){
    int T = 1;
    while(cin >> s){
        if(s[0] == '-')break;
        int N = s.size();
        for(int open = 0; open <= N; ++open){
            dp[N-1][open] = inf;
        }
        dp[N-1][1] = 0;
        if(s[N-1] == '{') dp[N-1][1] = 1;
        for(int k=N-2;k>=0;--k){
            for(int open = 0;open<=k;++open){
                if(open == 0){
                    if(s[k] == '{'){
                        dp[k][open] = dp[k+1][open+1];
                    } else {
                        dp[k][open] = 1 + dp[k+1][open+1];
                    }
                } else {
                    if(s[k] == '}'){
                        dp[k][open] = min(dp[k+1][open-1], 1+dp[k+1][open+1]);
                    } else {
                        dp[k][open] = min(dp[k+1][open+1], 1+dp[k+1][open-1]);
                    }
                }
                if(k==0)break;
            }
        }
        printf("%d. %d\n", T++, dp[0][0]);
    }
    return 0;
}