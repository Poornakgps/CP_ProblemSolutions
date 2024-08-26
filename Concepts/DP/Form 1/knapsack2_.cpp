// state rotation

#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n, W, v[105], w[105];
ll dp[105][100005];

ll rec(int ind , ll profit){

    if(ind == n){
        if(profit==0)
            return 0;
        else{
            return 9e9;
        }
    }

    if(dp[ind][profit]!=-1) return dp[ind][profit];

    ll ans = rec(ind+1, profit);

    if(profit>=v[ind]){
       ans = min(ans, rec(ind+1, profit - v[ind])+ w[ind] );
    }

    return dp[ind][profit] = ans;
}
void solve(){

    cin>>n>>W;
    for(int i=0; i<n; i++){
        cin>>w[i]>>v[i];
    }

    ll ans = 0;
    memset(dp, -1, sizeof(dp));

    for(ll profit=1; profit<=100000; profit++){

        if(rec(0, profit)<=W){
            // if(profit == 10){
            //     cout<<"FDDFSDADSF\n";
            // }
            ans = profit;
        }
    }
    cout<<ans<<endl;
}

int main(){
    solve();
}