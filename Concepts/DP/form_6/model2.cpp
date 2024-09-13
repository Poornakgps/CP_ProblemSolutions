#include<bits/stdc++.h>

using namespace std;

vector<int> adj[101];
int arr[101];
int sz[101];
int dp[101][2][101];
int n, k;

void dfs(int node, int p){

    for(int i=0; i<=k; i++){
        dp[node][1][i] = (i==1 ? arr[node] : -1e9);
        dp[node][0][i] = (i==0 ? 0 : -1e9);
    }
    for(auto v: adj[node]){
        dfs(v, node);
        
        for(int a=sz[node]; a>=0; a--){
            for(int b = sz[v]; b>=0; b--){
                dp[node][0][a+b] = max(dp[node][0][a+b], dp[node][0][a] + max(dp[v][0][b], dp[v][1][b]));
                dp[node][1][a+b] = max(dp[node][1][a+b], dp[node][1][a]+ dp[v][0][b]);
            }
        }
        sz[node]+= sz[v];
    }
}

int main(){

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
    }
    memset(dp, -1, sizeof(dp));
    dfs(1, 0);
    cout<<max(dp[1][0][k], dp[1][1][k])<<endl;
    return 0;
}