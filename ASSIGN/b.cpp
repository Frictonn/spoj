#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

long long dp[1050000];
int like[21][21];
int N;
int vis[1050000];
int main(){
    int tc;
    queue<pair<int,int> > q;
    cin >> tc;
    while(tc--){
        cin >> N;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cin >> like[i][j];
            }
        }
        int NMAX = (1<<N), bm;
        for(int i=0;i<NMAX;++i) {
            dp[i] = 0;
            vis[i] = 0;
        }
        
        dp[NMAX-1] = 1;
        q = queue<pair<int,int> > ();
        q.push(make_pair(0, NMAX-1));
        vis[NMAX-1] = 1;
        while(!q.empty()){
            pair<int,int> t = q.front();
            q.pop();
            int k = t.first;
            int bm = t.second;
            //printf("%d %d\n", k, bm);
            if(bm == 0) break;
            for(int i=0;i<N;++i){
                if(like[k][i] && (bm & (1<<i))){
                    dp[bm ^ (1<<i)] += dp[bm];
                    if(!vis[bm^(1<<i)]) {
                        vis[bm^(1<<i)] = 1;
                        q.push(make_pair(k+1, bm^(1<<i)));
                    }
                }
            }
        }
        cout << dp[0] << endl;
    }
    return 0;
}