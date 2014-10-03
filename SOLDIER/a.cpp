#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int,int> > pq[6];
vector<pair<int,int> > a[6];
int t, n;

int main(){
    cin >> n >> t;
    int u, p, q;
    for(int i=0;i<6;++i){
        pq[i].clear();
        a[i].clear();
    }
    for(int i=0;i<n;++i){
        cin >> u >> p >> q;
        pq[u-1].push_back(make_pair(p,q));
    }
    for(int i=0;i<6;++i){
        if(pq[i].empty()){
            printf("0\n");
            return 0;
        }
    }
    for(int i=0;i<pq[0].size();++i){
        a[0].push_back(pq[0][i]);
    }
    int ans = 0;
    for(int i=1;i<6;++i){
        for(int j=0;j<a[i-1].size();++j){
            for(int k=0;k<pq[i].size();++k){
                int tmp = pq[i][k].first + a[i-1][j].first;
                int low = min(pq[i][k].second, a[i-1][j].second);
                if(tmp > t) continue;
                a[i].push_back(make_pair(tmp,low));
                if(i==5) ans = max(ans, low);
            }
        }
    }
    if(a[5].empty()) {
        printf("0\n");
        return 0;
    }
    cout << ans << endl;
    return 0;
}
        