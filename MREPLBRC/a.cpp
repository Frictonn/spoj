#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
long long MOD = (long long) 1e5;
string str;
long long ways[203][203];
int N;

/* wrong logic. almost right actually! */

long long cnt(int i, int j){
    if(i >= j) return 1;
    long long ret = 1;
    if(str[i]=='{'){
        if(str[j]=='}' || str[j]=='?'){
            ret = ways[i+1][j-1];
        }
    } else if(str[i]=='('){
        if(str[j]==')' || str[j]=='?'){
            ret = ways[i+1][j-1];
        }
    } else if(str[i]=='['){
        if(str[j]==']' || str[j]=='?'){
            ret = ways[i+1][j-1];
        }
    } else if(str[i]=='?'){
        if(str[j]=='?'){
            ret = 3*ways[i+1][j-1];
        } else {
            ret = ways[i+1][j-1];
        }
    }
    ret %= MOD;
    return ret;
}

void solve(){
    for(int i=1;i<N;++i){
        ways[i][i-1] = 1;
    }
    for(int k=1;k<N;k+=2){
        for(int i=0;i+k<N;++i){
            int j=i+k;
            ways[i][j] = 0;
            for(int m=i+1;m<=j;m+=2){
                ways[i][j] += cnt(i,m) * cnt(m+1,j);
                ways[i][j] %= MOD;
            }
            printf("%d %d %lld\n",i,j, ways[i][j]);
        }
    }
    printf("%lld\n", ways[0][N-1]);
}

int main(){
    scanf("%d", &N);
    cin >> str;
    solve();
    return 0;
}