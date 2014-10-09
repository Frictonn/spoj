#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;

pair<pair<int,int>, int> m[10003];
int dp[10003];
int N;

int mfind(int val){
    int lo = 0, hi = N-1, mid;
    while(lo <= hi) {
        mid = (lo+hi)/2;
        if(m[mid].first.first < val){
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    return lo;
}

int main(){
    int tc;
    int u,v,w;
    cin >> tc;
    while(tc--){
        cin >> N;
        for(int i=0;i<N;++i){
            scanf("%d %d %d", &u, &v, &w);
            m[i] = make_pair(make_pair(u,v), w);
        }
        sort(m, m+N);
        dp[N] = 0;
        for(int k=N-1;k>=0;--k){
            dp[k] = max(dp[k+1], dp[mfind(m[k].first.first + m[k].first.second)] + m[k].second);
        }
        printf("%d\n", dp[0]);
    }
    return 0;
}