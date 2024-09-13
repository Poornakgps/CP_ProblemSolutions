#include<bits/stdc++.h>

using namespace std;

// Min number of edges required to break to make graph DAG TC: (N^2 (2^N))
// key idea: find best Topological permuatation that has min back edges

int n;
int edge[15][15];
int dp[1<<(15)];

int mask_rec(int pos, int mask){

    if(pos == n+1){
        return 0;
    }
    // cout<<dp[mask]<<endl;
    if(dp[mask]==-1){
        int ans = 1e9;
        for(int j=0; j<n; j++){

            if((1<<j)&mask) continue;

            int temp = 0;

            for(int i = 0; i<n; i++){
                if(mask&(1<<i)) temp += edge[j][i];
            }
            // cout<<temp<<endl;
            ans = min(ans, mask_rec(pos+1, mask | (1<<j)) +  temp);
        }
        dp[mask] = ans;
    }
    return dp[mask];
}

signed main(){
    int t;
    cin>>t;

    while(t--){
        cin>>n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>edge[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout<<mask_rec(1, 0)<<endl;
    }
}