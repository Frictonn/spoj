#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

map<pair<pair<int,int>, pair<int,int> > , long long> dp;
string str;
int N;
int MOD = (int) 1e5;

/* wrong approach, can get equal number of open and closed brackets,
but not balanced stackwise */

int rec(int k, int a, int b, int c){
    if(a < 0 || b < 0 || c < 0) return 0;
    if(k == N){
        if(a+b+c == 0) return 1;
        else return 0;
    }
    if(dp.find(make_pair(make_pair(k,a),make_pair(b,c))) != dp.end()) return dp[make_pair(make_pair(k,a),make_pair(b,c))];
    if(str[k] == '{')
        return rec(k+1, a+1, b, c);
    if(str[k] == '(')
        return rec(k+1, a, b+1, c);
    if(str[k] == '[')
        return rec(k+1, a, b, c+1);
    if(str[k] == '}')
        return rec(k+1, a-1, b, c);
    if(str[k] == ')')
        return rec(k+1, a, b-1, c);
    if(str[k] == ']')
        return rec(k+1, a, b, c-1);
    if(str[k] == '?'){
        int ret = 0;
        if(a>0)ret += rec(k+1, a-1, b, c);
        ret %= MOD;
        if(b>0)ret += rec(k+1, a, b-1, c);
        ret %= MOD;
        if(c>0)ret += rec(k+1, a, b, c-1);
        ret %= MOD;
        ret += rec(k+1, a+1, b, c);
        ret %= MOD;
        ret += rec(k+1, a, b+1, c);
        ret %= MOD;
        ret += rec(k+1, a, b, c+1);
        ret %= MOD;
        dp[make_pair(make_pair(k,a), make_pair(b,c))] = ret;
        return ret;
    }        
}

int main(){
    scanf("%d", &N);
    cin >> str;
    printf("%d\n", rec(0,0,0,0));
    return 0;
}