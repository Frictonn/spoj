#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int inf = (int) 1e9;
vector<vector<pair<int,pair<int,int> > > > adj; //indegree edges
int dp[10001][101];
int fw[101][101]; // min distance with zero cost
int K, N, R;
/*
S(c, n) : shortest distance from source to n using at most c cost.
S(c, n) = min { S(c - cost[u,n], u) + dist[u,n] } but be careful c != 0!
after checking all, check for c = 0 for each particular k. O(N^2*K)
*/

/* Time limit Exceeded for sure */

/* Whatt got accepted. */
int solve() {
    for(int k=1;k<=N;++k){
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                fw[i][j] = min(fw[i][k] + fw[k][j], fw[i][j]);
            }
        }
    }
    for(int i=1;i<=N;++i){
        dp[0][i] = fw[1][i];
    }
    for(int k=1;k<=K;++k){
        for(int v=1;v<=N;++v){
            dp[k][v] = dp[k-1][v];
            for(int i=0;i<adj[v].size();++i){
                int u = adj[v][i].first;
                int c = adj[v][i].second.first;
                int d = adj[v][i].second.second;
                if(k - c < 0 || c == 0) continue;
                dp[k][v] = min(dp[k - c][u] + d, dp[k][v]);
            }
        }
        for(int u=1;u<=N;++u){
            for(int v=1;v<=N;++v){
                if(fw[u][v] != inf){
                    dp[k][v] = min(dp[k][u] + fw[u][v], dp[k][v]);
                }
            }
        }
    }
    /*
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            printf("%d ", fw[i][j]);
        }
        printf("\n");
    }
    for(int k=0;k<=K;++k){
        printf("k = %d\n", k);
        for(int i=1;i<=N;++i){
            printf("%d ", dp[k][i]);
        }
        printf("\n");
    }
    */
    return (dp[K][N] < inf) ? dp[K][N] : -1;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> K >> N >> R;
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                fw[i][j] = inf;
            }
            fw[i][i] = 0;
        }
        int u,v,c,d;
        adj = vector<vector<pair<int, pair<int,int> > > > (N+3);
        for(int i=0;i<R;++i){
            cin >> u >> v >> d >> c;
            adj[v].push_back(make_pair(u, make_pair(c,d)));
            if(c == 0){
                fw[u][v] = min(fw[u][v], d);
            }
        }
        cout << solve() << endl;
    }
    return 0;
}