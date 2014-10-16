#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
Idea: O(n) solution, one-pass
maintain two indices head, tail.
If sum(head, tail) <= B, update answer
else, increase head until sum(head, tail) <= B
*/

int a[100003];
int sum[100003];
int B;
int N;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        scanf("%d", &N);
        scanf("%d", &B);
        sum[0] = 0;
        for(int i=1;i<=N;++i){
            scanf("%d", &a[i]);
            sum[i] = a[i] + sum[i-1];
        }
        int station = 0, people = 0;
        for(int head=1, tail=1; head <= N; ++head){
            while(tail <= head && sum[head] - sum[tail-1] > B){
                ++tail;
            }
            if(tail > head) continue;
            int cur = head - tail + 1;
            if(cur > station){
                station = cur;
                people = sum[head] - sum[tail-1];
            } else if(cur == station){
                people = min(people, sum[head] - sum[tail-1]);
            }
        }
        printf("%d %d\n", people, station);
    }
    return 0;
}