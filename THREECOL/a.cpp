#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int deg[100003];
int child[100003][3];
int dpmax[100003][3], dpmin[100003][3];
vector<int> stack;
string spec;
int N;

int recmax(int node, int col) {
    if(dpmax[node][col] != -1) return dpmax[node][col];
    int ret = 0;
    if (deg[node] == 1) {
        for(int i=0;i<3;++i){
            if(col == i) continue;
            ret = max(ret, recmax(child[node][0], i));
        }
    } else if(deg[node] == 2) {
        int u = (col+1)%3;
        int v = (col+2)%3;
        ret = max(recmax(child[node][0], u) + recmax(child[node][1], v),
                  recmax(child[node][0], v) + recmax(child[node][1], u));
    }
    if (col == 0) ++ret;
    dpmax[node][col] = ret;
    return ret;
}

int recmin(int node, int col) {
    if(dpmin[node][col] != -1) return dpmin[node][col];
    int ret = 123456;
    if (deg[node] == 0) {
        ret = 0;
    } else if (deg[node] == 1) {
        for(int i=0;i<3;++i){
            if(col == i) continue;
            ret = min(ret, recmin(child[node][0], i));
        }
    } else if(deg[node] == 2) {
        int u = (col+1)%3;
        int v = (col+2)%3;
        ret = min(recmin(child[node][0], u) + recmin(child[node][1], v),
                  recmin(child[node][0], v) + recmin(child[node][1], u));
    }
    if (col == 0) ++ret;
    dpmin[node][col] = ret;
    return ret;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        cin >> spec;
        stack.clear();
        N = spec.size();
        for(int i=N-1; i>=0; --i){
            deg[i+1] = spec[i] - '0';
            for(int j=0;j<deg[i+1];++j){
                child[i+1][j] = stack.back();
                stack.pop_back();
            }
            stack.push_back(i+1);
        }
        for(int i=0;i<=N;++i){
            for(int j=0;j<3;++j){
                dpmin[i][j] = -1;
                dpmax[i][j] = -1;
            }
        }
        int ansmax = 0, ansmin = 123456;
        for(int i=0;i<3;++i){
            ansmax = max(ansmax, recmax(1, i));
        }
        for(int i=0;i<3;++i){
            ansmin = min(ansmin, recmin(1, i));
        }
        printf("%d %d\n", ansmax, ansmin);
    }
    return 0;
}