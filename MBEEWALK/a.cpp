#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
IDEA 1:
S(n, k) = number of ways of n steps walk from source to point k.
S(n, k) = sum [i adj k] { S(n-1, i) }
Base:
S(0, i) = 1 for i == 0, 0 anywhere else
*/

/*
IDEA 2:
every hexagon is a state with coordinates:
(x, y)
(x, y) is adj to:
{ (x+1, y), (x-1, y), (x, y-1), (x+1, y-1), (x, y+1), (x-1, y+1) }
S(x, y, n) = number of n steps walk from (0, 0) to (x,y)
S(x, y, n) = sum_{all adj to x,y} { S(..., n-1) }
*/

int dp[20][50][50];
//centralized on (20, 20)
int solve () {
    for(int x=-14; x<=14; ++x){
        for(int y=-14; y<=14; ++y){
            dp[0][x+20][y+20] = 0;
        }
    }
    dp[0][20][20] = 1;
    for(int k=1;k<=14;++k){
        for(int x=-14;x<=14;++x){
            for(int y=-14;y<=14;++y){
                int X = x+20;
                int Y = y+20;
                dp[k][X][Y] = dp[k-1][X+1][Y] + dp[k-1][X-1][Y] +
                              dp[k-1][X][Y-1] + dp[k-1][X+1][Y-1] +
                              dp[k-1][X][Y+1] + dp[k-1][X-1][Y+1];
            }
        }
    }
}

int main(){
    int tc, N;
    cin >> tc;
    solve();
    while(tc--){
        cin >> N;
        cout << dp[N][20][20] << endl;
    }
    return 0;
}