#include<bits/stdc++.h>
using namespace std;
#define ll long long

// number of k inversions in n length permutation
int main(){
        vector<vector<ll>> dp(1001, vector<ll>(1001, 0));
        ll mod = 1e9 + 7;
        for(int i=1; i<=1000; i++){
            dp[i][0] = 1;
        }
        dp[2][0] = dp[2][1] = 1;
        for(int i=3 ; i<=1000; i++){
            for(int j=1; j<=1000; j++){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j])%mod;
                if(j>=i)
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod)%mod;
            }
        }
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        
		cout<<dp[n][k]<<endl;
    }
}