#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <utility>
#include <cctype>
using namespace std;

char str[20000];
int cnt[27];
map<pair<int,int>, long long> NCR;
int N;

long long ncr(int n, int r){
    if(r==0) return 1;
    if(n<=0 || r<=0) return 0;
    if(NCR.find(make_pair(n,r)) != NCR.end()) return NCR[make_pair(n,r)];
    long long ret = ncr(n-1, r) + ncr(n-1, r-1);
    NCR[make_pair(n,r)] = ret;
    return ret;
}

int main(){
    while(scanf("%[^\n]%*c", str) != EOF){
        for(int i=0;i<26;++i) cnt[i] = 0;
        N = strlen(str);
        int n = 0;
        for(int i=0;i<N;++i){
            if(isalpha(str[i])){
                ++n;
                ++cnt[tolower(str[i])-'a'];
            }
        }
        int odd = -1;
        bool ok = true;
        for(int i=0;i<26;++i){
            if(cnt[i]%2){
                if(odd == -1){
                    odd = i;
                } else {
                    ok = false;
                    break;
                }
            }
        }
        if(!ok) {
            printf("0\n");
        } else {
            if(odd != -1) {
                --n;
                --cnt[odd];
            }
            for(int i=0;i<26;++i){
                cnt[i] /= 2;
            }
            n /= 2;
            long long ans = 1;
            for(int i=0;i<26;++i){
                ans *= ncr(n, cnt[i]);
                n -= cnt[i];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}