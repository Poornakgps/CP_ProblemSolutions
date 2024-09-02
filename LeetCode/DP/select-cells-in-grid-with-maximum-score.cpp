#include<bits/stdc++.h>

using namespace std;

#define ll long long

int dp[101][1025];
vector<vector<int>> adj;
int rec(int val, int mask){

    if(val== adj.size()) return 0;
    if(dp[val][mask]!=-1) return dp[val][mask];

    int ans = rec(val + 1, mask);

    for(auto it: adj[val]){

        int bit = 1<<it;

        if((mask & bit) == 0){
            ans = max(ans, rec(val+1, bit | mask) + val);
        }
    }
    return dp[val][mask] = ans;
}

int main(){
    int n, m;
    cin >> n >> m;

    adj.resize(101);
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            adj[x].push_back(i);
        }
    }
    cout<<rec(0,0)<<endl;
}