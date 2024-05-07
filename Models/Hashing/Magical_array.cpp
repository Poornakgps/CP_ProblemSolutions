#include <bits/stdc++.h>

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

// https://codeforces.com/contest/1704/problem/D
void solve() {

    ll m, n; cin>> m>> n;
    ll mn=1e18, mx=0, ans=0;
    for(int i=1;i<=m;i++){
        ll sum=0;
        for(ll j=1;j<=n;j++){
            ll c; cin>> c;
            sum+=j*c;
        }
        if(sum>mx) ans=i; 
        mx=max(sum, mx);
        mn=min(mn, sum);
    }
    cout<< ans<<" "<< mx-mn<< endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}