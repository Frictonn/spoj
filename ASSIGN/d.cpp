#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

long long dp[1050000];
int like[21][21];
int N;

/*
BOTTOM-UP strategy:
just run down from NMAX to 0, 
since we can only assign to bits which is still off,
each time we are assigning a bit ON, we will access
an already completely computed sub problem
*/

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> N;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cin >> like[i][j];
            }
        }
        int NMAX = (1<<N);
        for(int i=0;i<NMAX;++i) {
            dp[i] = 0;
        }
        dp[NMAX-1] = 1;
        for(int b=NMAX-1;b>=0; --b) {
            int n = b;
            int k = 0;
            while(n){
                k += (n&1);
                n /= 2;
            }
            for(int i=0;i<N;++i){
                if(like[k][i] && !(b & (1<<i))){
                    dp[b] += dp[b | (1<<i)];
                }
            }
        }
        cout << dp[0] << endl;
    }
    return 0;
}