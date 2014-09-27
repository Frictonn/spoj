#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int inf = (int) 1e9;
int par[100003];
int dp[100003][2];
vector<vector<int> > adj;
int vis[100003];

void dfs(int u){
    vis[u] = 1;
    for(int i=0;i<adj[u].size();++i){
        int v = adj[u][i];
        if(!vis[v]){
            par[v] = u;
            dfs(v);
        }
    }
}

int rec(int u, int col){
    if(dp[u][col] != -1) return dp[u][col];
    int ret = col;
    bool leaf = true;
    for(int i=0;i<adj[u].size();++i){
        int v = adj[u][i];
        if(par[u] == v) continue;
        leaf = false;
        if(col == 0){
            ret += rec(v,1);
        } else {
            ret += min(rec(v,1), rec(v,0));
        }
    }
    if(leaf){
        dp[u][col] = col;
    } else {
        dp[u][col] = ret;
    }
    return ret;
}

int main(){
    int N;
    cin >> N;
    adj = vector<vector<int> > (N+3);
    for(int i=0;i<N-1;++i){
        int u,v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    for(int i=0;i<N;++i){
        vis[i] = 0;
        par[i] = -1;
        dp[i][0] = dp[i][1] = -1;
    }
    dfs(0);
    int ans = min(rec(0,0), rec(0,1));
    cout << ans << endl;
    return 0;
}