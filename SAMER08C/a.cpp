#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int v[100003], h[100003];
int a[100003];
int N, M;

int main(){
    while( scanf("%d %d", &N, &M), N+M != 0 ) {
        for(int k=0;k<N;++k){
            for(int i=0;i<M;++i){
                scanf("%d", &a[i]);
            }
            h[M] = h[M+1] = 0;
            for(int i=M-1;i>=0;--i){
                h[i] = max(h[i+2] + a[i], h[i+1]);
            }
            v[k] = h[0];
        }
        h[N] = h[N+1] = 0;
        for(int i=N-1;i>=0;--i){
            h[i] = max(h[i+2] + v[i], h[i+1]);
        }
        printf("%d\n", h[0]);
    }
    return 0;
}