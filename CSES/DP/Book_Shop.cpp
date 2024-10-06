#include<bits/stdc++.h>

using namespace std;
#define vi vector<int>

#define ll long long

#define mod 1000000007

int memo[1010][100100];
int n;
vi price(1010), pages(1010);
int rec(int ind, int x){
    if(x<0){
        return -1e9;
    }
    if(ind==n){
        return 0;
    }
    if(memo[ind][x]!=-1) return memo[ind][x];

    return memo[ind][x] = max(rec(ind+1, x), pages[ind] + rec(ind+1, x-price[ind]));
}
void solve(){
    ll x;
    cin>>n>>x;


    for(int i=0; i<n; i++){
        cin>>price[i];
    }
    for(int i=0; i<n; i++){
        cin>>pages[i];
    }
    // memset(memo, -1, sizeof(memo));
    // cout<<rec(0, x);
    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }

    cout << dp[x] << endl;
}
signed main(){

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}