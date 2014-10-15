#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

map<pair<int,pair<int,int> >, int> dp;
int H[3] = {3, -5, -20};
int A[3] = {2, -10, 5};

int rec(int h, int a, int st){
    if(h <= 0 || a <= 0) return 0;
    if(dp.find(make_pair(h,make_pair(a,st))) != dp.end()) return dp[make_pair(h,make_pair(a,st))];
    int ret = 1 + max(rec(h + H[(st+1)%3], a + A[(st+1)%3], (st+1)%3),
                  rec(h + H[(st+2)%3], a + A[(st+2)%3], (st+2)%3));
    dp[make_pair(h, make_pair(a,st))] = ret;
    return ret;
}
    

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int h, a;
        cin >> h >> a;
        dp.clear();
        int ans = 0;
        for(int i=0;i<3;++i){
            ans = max(ans, rec(h+H[i],a+A[i],i));
        }
        cout << ans << endl;
    }
    return 0;
}