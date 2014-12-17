#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/* knapsack
S(i, n) = max weight <= n from 1..i
S(i, n) = S(i-2, n-w[i]) + w[i] 
       or S(i-1, n)
*/

int S[1003][1003];
int w[1003];
int N, W;
int main(){
	int TC,tc=1;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &N, &W);
		for(int i=1;i<=N;++i){
			scanf("%d", &w[i]);
		}
		for(int i=0;i<=W;++i) S[0][i] = 0;
		for(int i=1;i<=N;++i){
			for(int j=0;j<=W;++j){
				S[i][j] = 0;
				if(i > 0) S[i][j] = max(S[i][j], S[i-1][j]);
				if(j >= w[i]) S[i][j] = max(S[i][j], S[max(0,i-2)][j-w[i]] + w[i]);
			}
		}
		printf("Scenario #%d: %d\n", tc++, S[N][W]);
	}
	return 0;
}