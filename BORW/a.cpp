#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[203];
int lis[203], Lis[203];
int lds[203], Lds[203];
int num[1000003];
int N;

// still wrong

void solve(){
    for(int i=N-1;i>=0;--i){
        lis[i] = 1;
        lds[i] = 1;
        for(int j=i+1;j<N;++j){
            if(a[j] > a[i]){
                lis[i] = max(lis[i], 1+lis[j]);
            } else if(a[j] < a[i]){
                lds[i] = max(lds[i], 1+lds[j]);
            }
        }
    }
    for(int i=0;i<N;++i){
        Lis[i] = 1;
        Lds[i] = 1;
        for(int j=i-1;j>=0;--j){
            if(a[j] < a[i]){
                Lis[i] = max(Lis[i], 1 + Lis[j]);
            } else if(a[j] > a[i]){
                Lds[i] = max(Lds[i], 1 + Lds[j]);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<N;++i){
        int tot = 0;
        int tmp = 0;
        for(int j=0;j<=i;++j){
            for(int k=0;k<=i;++k){
                if(a[j] >= a[i] && a[k] <= a[i]) {
                    tmp = max(tmp, Lis[k] + Lds[j] - (j==k ? 1 : 0));
                }
            }
        }
        tot += tmp;
        tmp = 0;
        for(int j=i;j<N;++j){
            for(int k=i;k<N;++k){
                if(a[j] >= a[i] && a[k] <= a[i]) {
                    tmp = max(tmp, lis[j] + Lds[k] - (j==k ? 1 : 0));
                }
            }
        }
        tot += tmp;
        ans = max(ans, tmp);
    }
    printf("%d\n", N-ans);
}

int main(){
    while(scanf("%d", &N), N!=-1){
        for(int i=0;i<N;++i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}