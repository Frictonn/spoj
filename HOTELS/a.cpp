#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int s[300003], a[300003];
int N, M;

int main(){
    cin >> N >> M;
    s[0] = 0;
    for(int i=1;i<=N;++i){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    int head=1,tail=0,ans=0;
    for(;head<=N;++head){
        while(s[head] - s[tail] > M) ++tail;
        ans = max(ans, s[head] - s[tail]);
    }
    cout << ans << endl;
    return 0;
}