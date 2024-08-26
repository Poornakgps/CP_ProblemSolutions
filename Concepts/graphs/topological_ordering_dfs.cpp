#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> g;

vector<int> vis, topo;

void dfs(int node){
    vis[node] = 1;

    for(auto v: g[node]){
        if(!vis[node]){
            dfs(v);
        }
    }
    topo.push_back(node);

}

int dp[1000005];
// for longest path in a DAG
int rec(int node){

    if(dp[node]!=-1) return dp[node];
    int ans = 1;

    for(auto v: g[node]){
        if(!vis[node]){
            ans = max(ans, 1 + rec(v));
        }
    }
    return dp[node] = ans;
}

signed main(){

    int n, m;

    cin >> n >> m;

    g.resize(n+1);
    vis.assign(n+1, 0);

    for(int i=0; i<m; i++){
        int a, b;

        cin >> a >> b;
        g[a].push_back(b);
    }
    memset(dp, -1, sizeof(dp));

    int ans = 1;
    
    // recursive approach
    // for(int i=1; i<=n; i++){
    //     ans = max(ans, rec(i));
    // }
    // cout<<ans<<endl;

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    // reverse(topo.begin(), topo.end());

    // for(auto it: topo){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    // iterative approach bottom to top
    int longest_length = 0;
    for(auto node: topo){
        int ans = 1;
        for(auto v: adj[node]){
            ans = max(ans, 1 + dp[v]);
        }
        dp[node] = ans;
        longest_length = max(longest_length, dp[node]);
    }
    cout<<longest_length<<endl;
}