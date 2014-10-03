#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long sum[12];
long long dsum[12];
long long pow10[12];

long long rec(int N, int k){
    //printf("%d %d\n", N, k);
    if(k == 0) return 0;
    long long ret = 0;
    long long head = (N / pow10[k-1]) %10;
    long long tail = N % pow10[k-1];
    //printf("%lld %lld \n", head, tail);
    if(head > 0) ret += head * sum[k-1] + dsum[head-1] * pow10[k-1] + head * (tail + 1);
    return ret + rec(N, k-1);
}

int main(){
    dsum[0] = 0;
    dsum[1] = 1;
    pow10[0] = 1;
    pow10[1] = 10;
    sum[0] = 0;
    sum[1] = 45;
    for(int i=2;i<12;++i){
        pow10[i] = pow10[i-1]*10;
        dsum[i] = dsum[i-1] + i;
        sum[i] = sum[1]*pow10[i-1] + sum[i-1]*10;
    }
    /*
    for(int k=0;k<3;++k){
        for(int i=0;i<12;++i){
            if(k==0) printf("%lld ", pow10[i]);
            if(k==1) printf("%lld ", dsum[i]);
            if(k==2) printf("%lld ", sum[i]);
        }
        printf("\n");
    }
    */
    int a, b;
    while(cin >> a >> b){
        if(a == -1 && b==-1) break;
        int n=0,m=0;
        int tmp = b;
        while(tmp){
            ++n;
            tmp /= 10;
        }
        tmp = a-1;
        while(tmp > 0){
            ++m;
            tmp /= 10;
        }
        long long x,y;
        x = rec(b,n);
        y = rec(a-1,m);
        cout << (x-y) << endl;
    }
    return 0;
}