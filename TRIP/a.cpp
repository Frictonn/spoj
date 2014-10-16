#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

string a,b;
int dp[90][90];
int M, N;
int len;
char path[90];
set<string> ans;

/*
TLE with normal recursion on string building
the idea is on each k, we can have only 26 choices
so just iterate through on these choices, therefore the
subproblem will not overlap as the result
This idea conceptually is very similar to DFS

Another important thing:
each time we are incrementally building the string,
we have to check that the lcs(i,j) + cur_length == target_length

*/

void gen(int i, int j, int k){
    if(k == len){
        ans.insert(path);
        return;
    }
    if(i < 0 || j < 0) return;
    for(char ch='a'; ch<='z'; ++ch){
        int cur_i = i, cur_j = j;
        int found_a = 0, found_b = 0;
        for(;cur_i >= 0; --cur_i){
            if(a[cur_i] == ch){
                found_a = 1;
                break;
            }
        }
        for(;cur_j >= 0; --cur_j){
            if(b[cur_j] == ch){
                found_b = 1;
                break;
            }
        }
        if(!found_a || !found_b) continue;
        if(dp[cur_i][cur_j]+k+1 == len) {
            path[len-k-1] = ch;
            gen(cur_i-1, cur_j-1, k+1);
        }
    }
}

int main(){
    int tc;
    cin >> tc;
    bool flag = false;
    while(tc--){
        if(flag) cout << endl;
        cin >> a;
        cin >> b;
        ans.clear();
        M = a.size();
        N = b.size();
        for(int i=0;i<M;++i){
            dp[i][0] = 0;
        }
        for(int j=0;j<N;++j){
            dp[0][j] = 0;
        }
        for(int i=1;i<=M;++i){
            for(int j=1;j<=N;++j){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
            }
        }
        len = dp[M][N];
        path[len] = '\0';
        gen(M-1, N-1, 0);
        for(set<string>::iterator it = ans.begin(); it!=ans.end();++it){
            cout << *it << endl;
        }
        flag = true;
    }
    return 0;
}