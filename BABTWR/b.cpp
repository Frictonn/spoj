#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

/* ACCEPTED, Idea:
Bottom Up: sort all boxes and possible orientations in terms of width and height.
WLOG width < height, hence comparison can be done between widths and heights exclusively.
Then do checks similar to LIS
*/

vector<pair<pair<int,int>,int> > stack;
int box[33][3];
int dp[99];
int N;

int main(){
    while(cin >> N, N!=0){
        stack.clear();
        for(int i=0;i<N;++i){
            for(int j=0;j<3;++j){
                cin >> box[i][j];
            }
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<3;++j){
                int a = box[i][j];
                int b = box[i][(j+1)%3];
                int c = box[i][(j+2)%3];
                if(a>b) swap(a,b);
                stack.push_back(make_pair(make_pair(a,b),c));
            }
        }
        sort(stack.begin(), stack.end());
        dp[0] = stack[0].second;
        int ans = 0;
        for(int i=1;i<3*N;++i){
            int h = stack[i].first.first;
            int w = stack[i].first.second;
            dp[i] = 0;
            for(int j=i-1;j>=0;--j){
                int ch = stack[j].first.first;
                int cw = stack[j].first.second;
                if(ch < h && cw < w) dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += stack[i].second;
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
            