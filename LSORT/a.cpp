#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
A[i] are elements.
P[i] is the position of i in A[i].
X[i][k] = the value x (position of element i from the left) after we
used items [i+1 .. k] where we want to place i to the left.
Y[i][k] = the value x after we used items [k .. i-1] where we want 
to place i to the right.
X[i][k] = X[i][k-1] - (P[k] < P[i] ? 1 : 0);
Y[i][k] = Y[i][k+1] - (P[k] < P[i] ? 1 : 0);
*/

int A[1003];
int P[1003];
int X[1003][1003], Y[1003][1003];
int dp[1003][1003];
int N;
int INF = (int) 1e9;
void solve(){
    for(int i=0;i<N;++i){
        P[A[i]-1] = i;
    }
    /*
    for(int i=0;i<N;++i){
        printf("%d ", P[i]);
    }
    printf("\n");
    */
    for(int i=0;i<N;++i){
        X[i][i] = P[i];
        for(int k=i+1;k<N;++k){
            X[i][k] = X[i][k-1] - (P[k] < P[i] ? 1 : 0);
        }
    }
    /*
    for(int i=0;i<N;++i){
        for(int k=0;k<N;++k){
            if(k <= i) printf("%d ", X[i][i]);
            else printf("%d ", X[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    */
    for(int i=0;i<N;++i){
        Y[i][i] = P[i];
        for(int k=i-1;k>=0;--k){
            Y[i][k] = Y[i][k+1] - (P[k] < P[i] ? 1 : 0);
        }
    }
    /*
    for(int i=0;i<N;++i){
        for(int k=0;k<N;++k){
            if(k >= i) printf("%d ", Y[i][i]);
            else printf("%d ", Y[i][k]);
        }
        printf("\n");
    }
    */
    for(int i=0;i<N;++i){
        dp[i][i] = P[i]+1;
    }
    for(int k=1;k<N;++k){
        for(int i=0;i+k<N;++i){
            int j=i+k;
            int n=k+1;
            dp[i][j] = min(dp[i+1][j] + (X[i][j]+1)*n, dp[i][j-1] + (Y[j][i]+1)*n);
        }
    }
    printf("%d\n", dp[0][N-1]);
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        scanf("%d", &N);
        for(int i=0;i<N;++i){
            scanf("%d", &A[i]);
        }
        solve();
    }
    return 0;
}