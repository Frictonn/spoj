#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int dist[53][53], cost[53][53];
int N, t;

//I think this should be WA, havent submitted.

int floyd(){
    for(int k=0;k<N;++k){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(dist[i][j] > dist[i][k] + dist[k][j] && cost[i][k] + cost[k][j] <= t){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    cost[i][j] = cost[i][k] + cost[k][j];
                } else if(dist[i][j] == dist[i][k] + dist[k][j]){
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }
}

int main(){
    while(cin >> N, cin >> t, N+t!=0){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cin >> cost[i][j];
            }
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cin >> dist[i][j];
            }
        }
        floyd();
        /*
        for(int k=0;k<2;++k){
            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    if(k == 0) printf("%d ", cost[i][j]);
                    else printf("%d ", dist[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
        */
        printf("%d %d\n", cost[0][N-1], dist[0][N-1]);
    }
    return 0;
}