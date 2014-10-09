#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<vector<pair<int, pair<int, int> > > > adj;
priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
int K, N, R;
int dp[101][10001];
int inf = (int) 1e9;
int solve(){
    pq = priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > >();
    for(int i=1;i<=N;++i){
        for(int k=0;k<=K;++k){
            dp[i][k] = inf;
        }
    }
    dp[1][0] = 0;
    pq.push(make_pair(0, make_pair(1, 0)));
    while(!pq.empty()){
        pair<int,pair<int,int> > st = pq.top(); pq.pop();
        int d0 = st.first;
        int u = st.second.first;
        int k = st.second.second;
        if(dp[u][k] != d0) continue;
        if(u == N) break;
        for(int i=0;i<adj[u].size();++i){
            int v = adj[u][i].first;
            int c = adj[u][i].second.first;
            int d = adj[u][i].second.second;
            if(k + c <= K && dp[v][k+c] > d0 + d) {
                dp[v][k+c] = d0+d;
                pq.push(make_pair(d0+d, make_pair(v, k+c)));
            }
        }
    }
    /*
    for(int i=1;i<=N;++i){
        for(int k=0;k<=K;++k){
            printf("%d ", dp[i][k]);
        }
        printf("\n");
    }
    */
    int ans = inf;
    for(int i=0;i<=K;++i){
        ans = min(dp[N][i], ans);
    }
    if(ans == inf) return -1;
    else return ans;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> K >> N >> R;
        int u, v, d, c;
        adj = vector<vector<pair<int,pair<int,int> > > >(N+1);
        for(int i=0;i<R;++i){
            cin >> u >> v >> d >> c;
            adj[u].push_back(make_pair(v, make_pair(c,d)));
        }
        cout << solve() << endl;
    }
    return 0;
}