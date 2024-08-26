#include <bits/stdc++.h>

using namespace std;


int n, s;
int a[1005];

int dp[1002][1002];

int rec(int i, int sum_left){

    if(sum_left<0){
        return 0;
    }

    if(i==n){
        if(sum_left==0){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dp[i][sum_left]!=-1){
        return dp[i][sum_left];
    }
    int ans = 0;
    for(int x = 0 ; x<=a[i]; x++){
        ans += rec(i+1, sum_left-x);
    }

    return dp[i][sum_left] = ans;
}

void solve(){
    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    memset(dp, -1, sizeof(dp)); 

    cout<<rec(0, s)<<endl; // recursive approach

    memset(dp, 0, sizeof(dp));
    
    // iterative approach
    for(int i=n; i>=0; i--){
        for(int sum_left = 0; sum_left<=s; sum_left++){
            // base case
            if(i==n){
                if(sum_left==0){
                    dp[i][sum_left] = 1;
                }
                else{
                    dp[i][sum_left] = 0;
                }
                continue;
            }
            for(int x = 0 ; x<=a[i]; x++){
                if(sum_left>=x){
                    dp[i][sum_left] += dp[i+1][sum_left-x];
                }
            }
        }
    }
    cout<<dp[0][s]<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}