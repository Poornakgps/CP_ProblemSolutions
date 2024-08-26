#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int> (m,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(a[i][j]){
                if(i>0){
                    dp[i][j]+=dp[i-1][j];
                }
                if(j>0){
                    dp[i][j]+=dp[i][j-1];
                }
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;

}

int main(){

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}