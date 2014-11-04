#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
long long MOD = (long long) 1e5;
string str;
long long ways[203][203];
int mark[203][203];
int N;

/* Accepted! */

pair<long long,int> cnt(int i, int j){
    long long ret = 0;
    int m = 0;
    if(str[i]=='{'){
        if(str[j]=='}' || str[j]=='?'){
            ret = ways[i+1][j-1];
            m = mark[i+1][j-1];
        }
    } else if(str[i]=='('){
        if(str[j]==')' || str[j]=='?'){
            ret = ways[i+1][j-1];
            m = mark[i+1][j-1];
        }
    } else if(str[i]=='['){
        if(str[j]==']' || str[j]=='?'){
            ret = ways[i+1][j-1];
            m = mark[i+1][j-1];
        }
    } else if(str[i]=='?'){
        if(str[j]=='?'){
            ret = 3*ways[i+1][j-1];
            m = mark[i+1][j-1];
        } else if(str[j]==')' || str[j]=='}' || str[j]==']'){
            ret = ways[i+1][j-1];
            m = mark[i+1][j-1];
        }
    }
    if(ret >= MOD){
        ret %= MOD;
        m = 1;
    }
    return make_pair(ret,m);
}

void solve(){
    for(int i=1;i<=N;++i){
        ways[i][i-1] = 1;
    }
    for(int k=1;k<N;k+=2){
        for(int i=0;i+k<N;++i){
            int j=i+k;
            ways[i][j] = 0;
            mark[i][j] = 0;
            for(int m=i+1;m<=j;m+=2){
                pair<long long, int> tmp = cnt(i,m);
                ways[i][j] += tmp.first * ways[m+1][j];
                if(ways[m+1][j] == 0 && mark[m+1][j] == 0){
                    mark[i][j] = 0;
                } else {
                    mark[i][j] |= tmp.second | mark[m+1][j];
                }
                if(ways[i][j] >= MOD){
                    mark[i][j] = 1;
                    ways[i][j] %= MOD;
                }
            }
        }
    }
    if(mark[0][N-1] == 0)printf("%lld\n", ways[0][N-1]);
    else printf("%05lld\n", ways[0][N-1]);
}

int main(){
    scanf("%d", &N);
    cin >> str;
    solve();
    return 0;
}