#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll dp[205][205], arr[205];
ll n;

ll rec(int i, int j){
    // cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    if(i>j) return 0;
    if(dp[i][j]!= -1){
        return dp[i][j];
    }

    ll tmp = 0;
    for(int k = i; k<=j; k++){
        ll lft_rgt = rec(i, k-1) + rec(k+1, j);

        ll score = (i>0 ? arr[i-1]: 1ll )*arr[k]*(j<n-1 ? arr[j+1]: 1ll);

        tmp = max(tmp, score + lft_rgt);
    }
    return dp[i][j] = tmp;
}

void solve(){

	cin >> n;
	
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // cerr<<"HEY\n";
    memset(dp, -1, sizeof(dp));
    cout<<rec(0, n-1)<<endl;
}

int main(){
    int t = 1;
    cin>>t;

    while(t--){
        solve();
    }
}