#include <bits/stdc++.h>
// https://abitofcs.blogspot.com/2015/01/codeforces-453b-little-pony-and-harmony.html
using namespace std;

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
#define pii pair<ll, ll>
typedef long long ll;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define endl() cout << endl
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"

// dp[i][j] dp[i][j] be the minimum answer one can get by changing the first i elements such that the set of primes used (i.e. the set of prime factors of the numbers b1, b2, ..., bi) is equal to the subset denoted by j

ll dp[105][(1<<17)];
ll par[105][(1<<17)];
ll val[64];

void Output(ll k, ll idx){
    if (k == 1){
        cout<<par[k][idx]<<" ";
        return;
    }
    Output(k - 1, idx ^ val[par[k][idx]]); 
    cout<<par[k][idx]<<" ";
}

void solve() {

    vector<bool> isprime(61, true);
    vector<ll> primes;
    for(int i=2; i<=60; i++){

        if(isprime[i]){
            for(int j=2*i; j<60; j+=i){
                isprime[j]= false;
            }
            primes.pb(i);
        }
    }

    for(int i=1; i<=60; i++){
        for(int j=0; j<primes.size(); j++){
            if(i%primes[j]==0){
                val[i]|=(1<<j);
            }
        }
    }

    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++)
        cin>>a[i];


    for(int i=1;i<=n;++i){
        for(int j=0;j<(1<<17);++j){
            dp[i][j] = 1e9;
        }
    }

    for(int i=1; i<=n; i++){

        for(int j=1; j<=60; j++){
            ll bm = ((1<<17)-1)^(val[j]);
            for(int k=bm;;k=(k-1)&bm){
                ll tmp = dp[i-1][k] + abs(a[i]-j);
                if(tmp < dp[i][k|val[j]]){
                    dp[i][k|val[j]] = tmp;
                    par[i][k|val[j]] = j;
                }
                if(k==0) break;
            }
        }
    }
    ll ans = 1e9;
    ll idx = -1;
    for(int j=0; j<(1<<17); j++){
        if(ans > dp[n][j]){
            ans = dp[n][j];
            idx = j;
        }
    }
    Output(n, idx);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}