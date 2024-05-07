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

// https://codeforces.com/problemset/problem/1419/C
void solve() {

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    ll sm=0, cnt=0;
    rep(i, 0, n, 1) cin >> a[i], sm+=a[i], cnt+= (a[i]==x);

    if(cnt==n) {
        cout << 0 << endl;
        return;
    }
    
    if(sm==x*n || cnt>0) {
        cout << 1 << endl;
        return;
    }
    cout<<2<<endl;
    
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