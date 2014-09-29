#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

int inf = (int) 1e9;
int x[1003], y[1003];
map<pair<pair<int,int>,pair<int,int> >, int > dp;

int M,N;
int rec(int L,int R, int U, int D){
    //printf("%d %d %d %d\n", L, R, U, D);
    if(L > R && U > D) return 0;
    if(dp.find(make_pair(make_pair(L,R),make_pair(U,D))) != dp.end()) return dp[make_pair(make_pair(L,R),make_pair(U,D))];
    int ans = inf;
    for(int i=L;i<=R;++i){
        ans = min(ans, x[i] + rec(L,i-1,U,D) + rec(i+1,R,U,D));
    }
    for(int i=U;i<=D;++i){
        ans = min(ans, y[i] + rec(L,R,U,i-1) + rec(L,R,i+1,D));
    }
    dp[make_pair(make_pair(L,R),make_pair(U,D))] = ans;
    return ans;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> M >> N;
        for(int i=1;i<M;++i){
            cin >> x[i];
        }
        for(int i=1;i<N;++i){
            cin >> y[i];
        }
        dp.clear();
        int ans = rec(1,M-1,1,N-1);
        cout << ans << endl;
    }
    return 0;
}