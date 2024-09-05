#include<bits/stdc++.h>

using namespace std;

// Min number of edges required to break to make graph DAG TC: (N^2 (2^N))
// key idea: find best Topological permuatation that has min back edges

int n, m;
int edge[21][21];
int dp[(1>>20)];

int mask_rec(int position, int mask){

    if(position == n+1){
        return 0;
    }

    if(dp[mask]!=-1){
        int ans = 1e9;
        for(int j=0; j<n; j++){

            if((1<<j)&mask) continue;

            int temp = 0;

            for(int i = 0; i<n; i++){
                if(mask&(1<<i)) temp += edge[j][i];
            }
            ans = min(ans, mask_rec(position+1, mask | (1<<j)) +  temp);
            
        }
        dp[mask] = ans;
    }
    return dp[mask];
}

signed main(){

    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        edge[x-1][y-1] = 1;
    }

    memset(dp, -1, sizeof(dp));

    cout<<mask_rec(1, 0)<<endl;

}