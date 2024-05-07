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

// https://codeforces.com/problemset/problem/1426/D

void solve() {

    ll n;
    cin >> n;
    
    vector<ll> a(n);

    for(auto &x : a) cin >> x;

    map<ll,ll> in;
    in[a[0]]++;
    ll ans=0;
    for(ll i = 1; i<n; i++){
        if(a[i]+a[i-1]==0 || in[a[i]+a[i-1]]>0){
            a[i]= a[i];
            in.clear();
            ans++;
        }
        else{
            a[i] = a[i]+ a[i-1];
        }
        in[a[i]]++;
    }
    cout << ans << endl;
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