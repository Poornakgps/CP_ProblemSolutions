#include<bits/stdc++.h>

using namespace std;

signed main(){

    int n, k;
    cin>>n>>k;

    int product[n][k];

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cin>>product[i][j];
        }
    }

    int dp[1<<k][n]; // 1<=k<=15, n<=50
    for(int i=0; i<k; i++){
        total[(1<<i)][0] = product[i][0];
    }
    
    for(int d=1; d<n; d++){
        for(int mask = 0; mask<(1<<k); mask++){
            total[mask][d] = total[mask][d-1];

            for(int x=0; x<k; x++){
                if((mask)&(1<<x)){
                    total[mask][d] = max(total[mask][d] , total[(mask^(1<<x))][d-1] + product[d][x]);
                }
            }
        }
    }
}