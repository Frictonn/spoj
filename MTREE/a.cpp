#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
long long MOD = (long long) 1e9 + 7;
long long DIV = (long long) 5e8 + 4;
vector<vector<pair<int,int> > > adj;
int vis[100003];
int par[100003];
long long path[100003];
int N;

/* TLE */

long long dfs(int u){
    if(vis[u]) return path[u];
    long long ret = 0;
    for(int i=0;i<adj[u].size();++i){
        int v = adj[u][i].first;
        long long w = adj[u][i].second;
        if(par[u] != v) {
            par[v] = u;
            ret += ((dfs(v) % MOD)+1LL)*w;
            ret %= MOD;
        }
    }
    vis[u] = 1;
    path[u] = ret;
    return ret;
}

void solve(){
    long long ans = 0;
    for(int u=1;u<=N;++u){
        for(int i=1;i<=N;++i){
            vis[i] = 0;
            par[i] = -1;
        }
        ans += dfs(u);
        ans %= MOD;
    }
    ans = (ans * DIV) % MOD;
    printf("%lld\n", ans);
}

int main(){
    int u, v, w;
    scanf("%d", &N);
    adj = vector<vector<pair<int,int> > >(N+3);
    for(int i=0;i<N-1;++i){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    solve();
    return 0;
}