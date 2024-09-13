#include<bits/stdc++.h>

using namespace std;

#define int long long

int n, m;
vector<int> adj[20];

int dp[20][(1<<20)];

int ways_mask(int node, int mask){
    if(mask == (1<<n)-1){
        if(node == n-1){
            return 1;
        }
        return 0;
    }

    if(dp[node][mask]!=-1){
        return dp[node][mask];
    }
    int ans = 0;
    for(auto v: adj[node]){
        if((mask&(1<<v))) continue;
        ans+=ways(v, mask | (1<<v));
    }

    return dp[node][mask] = ans;
}

signed main(){

    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(dp, -1, sizeof(dp));
    cout<<rec_mask(0, 0)<<endl;
}