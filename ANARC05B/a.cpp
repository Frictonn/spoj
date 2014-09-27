#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[10003][2];
int a[10003][2], n[2];
int s[20003][2];
int gen(){
    int i=0,j=0;
    for(int k=0;k<20003;++k){
        s[k][0] = s[k][1] = -1;
    }
    while(i<n[0] && j<n[1]){
        if(a[i][0] == a[j][1]){
            s[a[i][0]+10000][0] = i;
            s[a[i][0]+10000][1] = j;
            ++i; ++j;
        } else if(a[i][0] > a[j][1]){
            ++j;
        } else {
            ++i;
        }
    }
}

int rec(int k, int col){
    if(n[col] == k) return 0;
    if(dp[k][col] != -1) return dp[k][col];
    int cur = a[k][col];
    int opp = (col == 0)?1:0;
    int ret = 0;
    if(s[cur+10000][opp] != -1){
        ret = rec(s[cur+10000][opp]+1, opp);
    }
    ret = max(ret, rec(k+1,col));
    dp[k][col] = ret + cur;
    return dp[k][col];
}

int main(){
    while(cin >> n[0], n[0] != 0){
        for(int i=0;i<n[0];++i){
            cin >> a[i][0];
        }
        cin >> n[1];
        for(int j=0;j<n[1];++j){
            cin >> a[j][1];
        }
        for(int i=0;i<10003;++i){
            dp[i][0] = dp[i][1] = -1;
        }
        gen();
        int ans = max(rec(0,0),rec(0,1));
        cout << ans << endl;
    }
    return 0;
}