#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int dp[301][101][101];
int H, W;
string board[103];

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d%d",&W, &H);
		for(int i=0;i<H;++i){
			cin >> board[i];
		}
		dp[0][0][0] = (board[0][0] == '*' ? 1 : 0);
		for(int k=1;k<=H+W-2;++k){
			int left = max(0, k-H+1);
			int right = min(k, W-1);
			for(int i=left;i<=right;++i){
				for(int j=i;j<=right;++j){
					if(board[k-i][i] == '#' || board[k-j][j] == '#'){
						dp[k][i][j] = -123456;
						continue;
					}
					dp[k][i][j] = dp[k-1][i][j];
					if(i > 0) {
						dp[k][i][j] = max(dp[k][i][j], dp[k-1][i-1][j]);
					}
					if(j > 0) {
						dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j-1]);
					}
					if(i > 0 && j > 0) {
						dp[k][i][j] = max(dp[k][i][j], dp[k-1][i-1][j-1]);
					}
					if(i==j){
						if(board[k-i][i] == '*') dp[k][i][j]++;
					} else {
						if(board[k-i][i] == '*') dp[k][i][j]++;
						if(board[k-j][j] == '*') dp[k][i][j]++;
					}
				}
			}
		}
		printf("%d\n", dp[H+W-2][W-1][W-1]);
	}
	return 0;
}