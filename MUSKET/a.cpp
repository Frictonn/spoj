#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int win[103][103];
int can_meet[103][103];
int winner[103];
int N;
int ans;

int meet(int i, int j) {
    if ((i+1)%N == j || i==j) return 1;
    if (can_meet[i][j] != -1) return can_meet[i][j];
    //can i meet with j using a intermediary person?
    for(int mid = (i+1)%N; mid != j; mid = (mid+1)%N) {
        if(win[i][mid] || win[j][mid]){
            if(meet(i, mid) && meet(mid, j)){
                can_meet[i][j] = 1;
                return 1;
            }
        }
    }
    can_meet[i][j] = 0;
    return 0;
}

void solve(){
    for (int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(i==j || !win[i][j]) continue;
            if(meet(i, j) && meet(j, i)){
                winner[ans++] = i+1;
                break;
            }
        }
    }
    printf("%d\n", ans);
    for(int i=0;i<ans;++i){
        printf("%d\n", winner[i]);
    }
}


int main(){
    int tc;
    cin >> tc;
    while(tc--){
        ans = 0;
        cin >> N;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                scanf("%1d", &win[i][j]);
            }
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                can_meet[i][j] = -1;
            }
        }
        solve();
    }
    return 0;
}