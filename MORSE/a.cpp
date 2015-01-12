#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

/* TEDIOUS! */

string morse;
vector<string> dict;
int dicttree[200003][30];
vector<int> state[100003];
long long dp[100003];
int N, sz;
int dollar = 29;
string pattern[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};


void build_dict_tree(){
	for(int i=0;i<=200000;++i){
		for(int j=0;j<30;++j){
			dicttree[i][j] = 0;
		}
	}
	int cnt = 1;
	for(int i=0;i<N;++i){
		int cur = 0;
		int k = 0;
		while(dicttree[cur][dict[i][k]-'A'] != 0){
			cur = dicttree[cur][dict[i][k]-'A'];
			++k;
			if(k >= dict[i].size())break;
		}
		if(k == dict[i].size()){
			dicttree[cur][dollar] += 1;
		} else {
			while(k < dict[i].size()){
				dicttree[cur][dict[i][k]-'A'] = cnt;
				cur = cnt;
				++cnt;
				++k;
			}
			dicttree[cur][dollar] += 1;
		}
	}
}

void build_state(){
	for(int i=0;i<sz;++i){
		state[i].clear();
	}
	for(int i=0;i<sz;++i){
		for(int j=0;j<26;++j){
			bool ok = true;
			for(int k=0;k<pattern[j].size();++k){
				if(morse[i+k] != pattern[j][k]){
					ok = false;
					break;
				}
			}
			if(ok) state[i].push_back(j);
		}
	}
}

long long dfs(int u, int start, int trie){
	assert(u<=sz);
	if(u == sz){
		return dicttree[trie][dollar];
	}
	if(start == u) if(dp[u]!=-1)return dp[u];
	long long ret = 0;
	for(int i=0;i<state[u].size();++i){
		int c = state[u][i];
		if(dicttree[trie][c])ret += dfs(u+pattern[c].size(), start, dicttree[trie][c]);
	}
	if(dicttree[trie][dollar]){
		ret += 1LL*dicttree[trie][dollar] * dfs(u, u, 0);
	}
	if(start == u) {
		dp[u] = ret; 
	}
	return ret;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		cin >> morse;
		sz = morse.size();
		scanf("%d",&N);
		dict = vector<string>(N+3);
		for(int i=0;i<N;++i){
			cin >> dict[i];
		}
		build_dict_tree();
		build_state();
		for(int i=0;i<sz;++i){
			dp[i] = -1;
		}
		long long ans = dfs(0,0,0);
		cout << ans << endl;
	}
	return 0;
}