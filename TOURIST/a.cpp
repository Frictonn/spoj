#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

// WRONG IDEA!


string board[103];
int dp[103][103];
pair<int,int> par[103][103];
int H, W;

int solve(){
	dp[0][0] = (board[0][0] == '*' ? 1 : 0);
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			if(i==0 && j==0) continue;
			if(board[i][j] == '#') {
				dp[i][j] = -123456;
				continue;
			}
			if(i==0) {
				dp[i][j] = dp[i][j-1];
				par[i][j] = make_pair(i, j-1);
			} else if(j==0){
				dp[i][j] = dp[i-1][j];
				par[i][j] = make_pair(i-1, j);
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				if(dp[i-1][j] >= dp[i][j-1]){
					par[i][j] = make_pair(i-1,j);
				} else {
					par[i][j] = make_pair(i,j-1);
				}
			}
			dp[i][j] += (board[i][j] == '*' ? 1 : 0);
		}
	}
	return dp[H-1][W-1];
}

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d%d", &W, &H);
		for(int i=0;i<H;++i){
			cin >> board[i];
		}
		int k = solve();
		pair<int,int> cur = make_pair(H-1, W-1);
		while(1){
			board[cur.first][cur.second] = '.';
			if(cur.first == 0 && cur.second == 0) break;
			cur = par[cur.first][cur.second];
		}
		for(int i=0;i<H;++i){
			cout << board[i] << endl;
		}
		int _k = solve();
		printf("%d\n", k+_k);
	}
	return 0;
}