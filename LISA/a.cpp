#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long Long;
Long inf = (Long) 1e18;
Long dp[103][103];
Long a[103];
int op[103]; //0:+, 1:*

Long rec(int i, int j, int st){
    if(i == j) return a[i];
    if(i+1 == j) {
        if(op[i] == 0){
            return a[i] + a[j];
        } else {
            return a[i] * a[j];
        }
    }
    if(dp[i][j] != -1) return dp[i][j];
    Long ret = (st == 0)?0:inf, aa, b, c;
    for(int k=i;k<j;++k){
        aa = rec(i,k,st);
        b = rec(k+1,j,st);
        if(op[k] == 0){
            c = aa+b;
        } else {
            c = aa*b;
        }
        if(st == 0){
            ret = max(ret, c);
        } else {
            ret = min(ret, c);
        }
    }
    dp[i][j] = ret;
    return ret;
}

int main(){
    int TC;
    cin >> TC;
    getchar();
    while(TC--){
        int N=0;
        char ch;
        while((ch = getchar())!=EOF){
            //printf("%c",ch);
            if(ch == '\n') break;
            if(ch == '+'){
                op[N++] = 0;
            } else if(ch == '*'){
                op[N++] = 1;
            } else {
                a[N] = (ch - '0');
            }
        }
        ++N;
        //for(int i=0;i<N;++i){ printf("%lld ", a[i]); } printf("\n");
        //for(int i=0;i<N-1;++i){ printf("%d ", op[i]); } printf("\n");
        for(int i=0;i<=N;++i){
            for(int j=0;j<=N;++j){
                dp[i][j] = -1;
            }
        }
        Long ans1 = rec(0,N-1,0);
        for(int i=0;i<=N;++i){
            for(int j=0;j<=N;++j){
                dp[i][j] = -1;
            }
        }
        Long ans2 = rec(0,N-1,1);
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}