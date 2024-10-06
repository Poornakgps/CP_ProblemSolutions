#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<ll>
#define mod 1000000007


void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> dp(n+1, vector<ll>(m+2, 0));
    
    vi a(n);
    for(auto &i: a) cin>>i;

    if (a[0] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1;
        }
    }
    else{
        dp[0][a[0]]=1;
    }

    for(int i=1; i<n; i++){
        if(a[i]!=0){
            int j = a[i];
            dp[i][j] = dp[i-1][j-1]; 
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;  
            dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;  
            continue;
        }
        for(int j=1; j<=m; j++){
            dp[i][j] = dp[i-1][j-1];
            dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
            dp[i][j] = (dp[i][j] + dp[i-1][j+1])%mod;   
        }
    }
    int ans = 0;
    for(int i=1; i<=m; i++){
        ans = (ans + dp[n-1][i])%mod;
    }
    cout<<ans<<endl;
}

signed main(){

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}