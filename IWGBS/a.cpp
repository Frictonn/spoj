#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* requires big int */

long long dp[2][10003];
int N;

struct bigint {
    vector<int> digit;
    int len;
    
    bigint() { len = 1; digit = vector<int>(); digit.push_back(0); }
    
    void add(bigint& other) {
        int carry = 0;
        int n = min(other.len, len);
        for(int i=0;i<n;++i){
            digit[i] = digit[i] + other.digit[i] + carry;
            carry = 0;
            if(digit[i] > 9) {
                carry = digit[i]/10;
                digit[i] %= 10;
            }
        }
        if(other.len > len) {
            for(int i=n; i<other.len; ++i) {
                int tmp = other.digit[i] + carry;
                carry = 0;
                if(tmp > 9) {
                    carry = tmp/10;
                    tmp %= 10;
                }
                digit.push_back(tmp);
                ++len;
            }
            n = len;
        }
        while ( n < len && carry != 0) {
            digit[n] += carry;
            carry = 0;
            if(digit[n] > 9) {
                carry = digit[n]/10;
                digit[n] %= 10;
            }
            ++n;
        }
        while (carry != 0) {
            int tmp = carry;
            carry = 0;
            if(tmp > 9) {
                carry = tmp/10;
                tmp %= 10;
            }
            digit.push_back(tmp);
            ++len;
        }
    }
};

bigint B[2][10003];

int main(){
    cin >> N;
    /*
    dp[0][1] = dp[1][1] = 1;
    for(int k=2;k<=N;++k){
        dp[0][k] = dp[1][k-1];
        dp[1][k] = dp[0][k-1] + dp[1][k-1];
    }
    cout << (dp[1][N] + dp[0][N]) << endl;
    */
    
    B[0][1].digit[0] = 1;
    B[1][1].digit[0] = 1;
    for(int k=2;k<=N;++k){
        B[0][k] = B[1][k-1];
        B[1][k].add(B[0][k-1]);
        B[1][k].add(B[1][k-1]);
    }
    bigint ans = B[1][N];
    ans.add(B[0][N]);
    for(int i=ans.len-1;i>=0;--i){
        printf("%d", ans.digit[i]);
    }
    printf("\n");
    
    return 0;
}