#include<bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for(ll i = a; i < (b); i+=c)
#define all(x) begin(x), end(x)
typedef long long ll;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define endl() cout<<endl
#define Yes() cout<<"YES\n"
#define No() cout<<"NO\n"

void primeFactors(ll n, map<ll,ll> &mp) { 

    while (n % 2 == 0) { 
        mp[2]++;
        n = n/2; 
    } 
    for (ll i = 3; i <= sqrt(n); i = i + 2) { 
        while (n % i == 0) { 
            mp[i]++;
            n = n/i; 
        } 
    } 
    if (n > 2) 
        mp[n]++;
}

void solve() {
    ll n,m,k,d;
    cin>>n>>m>>k>>d;

    ll a[n][m];
    rep(i,0,n,1){
        rep(j,0,m,1){
            cin>>a[i][j];
        }
    }
    ll dp[n][m+1]={};
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
        pq.push({1, 0});

        for(int j=1; j<m; j++){
            if(j-d-1>0){
                while(pq.top().ss < j-d-1){
                    pq.pop();
                }
                dp[i][j] = pq.top().ff + a[i][j]+1;
                pq.push({dp[i][j], j});
            }
            else{
                dp[i][j] = 2 + a[i][j];
                pq.push({dp[i][j], j});
            }
        }
    }
    ll ans[n+1]={};
    for(int i=1; i<=n; i++){
        ans[i] = dp[i-1][m-1];
    }
    for(int i=1; i<=n; i++){
        ans[i]= ans[i]+ans[i-1];
    }
    ll minn=1e18;
    for(int i=k; i<=n; i++){
        minn= min(ans[i]-ans[i-k], minn);
    }
    cout<<minn<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}