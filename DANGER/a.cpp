#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

/*
1 2 3 4 5 6 7 8 9 10
1 3 5 7 9 .
3 7 .
7
S, state: 
a) 1, 2, 3, 4, ..., N (N even or odd)
b) start eliminating from 1 or from 2.
result of elimination:

N even: S(N, 2) = 2 * S(N/2, 2) - 1
N odd: S(N, 2) = 2 * S(ceil(N/2), 1) - 1
N odd: S(N, 1) = 2 * S(floor(N/2), 2) 
N even: S(N, 1) = 2 * S(N/2, 1) 
*/

int joseph(int N, int k) {
    if(N==1) {
        return 1;
    }
    if(N%2 == 0) {
        if(k == 1) {
            return 2*joseph(N/2, 1);
        } else {
            return 2*joseph(N/2, 2) - 1;
        }
    } else {
        if(k == 1) {
            return 2*joseph(N/2, 2);
        } else {
            return 2*joseph(N/2+1, 1) - 1;
        }
    }
}

int main(){
    string s;
    while(cin >> s){
        int x = s[0] - '0', y = s[1] - '0', z = s[3] - '0';
        if(x+y+z == 0) break;
        int N = 10*x + y;
        for(int i=0;i<z;++i){
            N *= 10;
        }
        printf("%d\n", joseph(N, 2));
    }
    return 0;
}