#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;

int dp[1000005];

int rec(int x){

    // base case
    if(x == 0){
        return 0;
    }

    // cache check
    if(dp[x] != -1){
        return dp[x];
    }

    int ans= 0;
    // transition
    for(int m = 0; (1<<m) <= x; m++){
        if(rec(x - (1<<m)) == 0){
            ans = 1;
            break;
        }
    }

    return dp[x] = ans;
}

void solve(){
    cin>>n;
    memset(dp, -1, sizeof(dp));
    cout<<rec(n)<<endl;
}


int main(){
    int t = 1;
    cin>>t;

    while(t--){
        solve();
    }
}