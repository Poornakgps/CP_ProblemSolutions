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


// https://codeforces.com/problemset/problem/1926/E
void solve() {

    ll n, k;
    cin >> n >> k;
    vector<ll> in;
    while(n){
        in.pb((n+1)/2);
        n/=2;
    }

    ll till_now = 0, p=1;
    for(auto it: in){
        if(till_now < k &&  k<= till_now + it){
            ll ans = p*(2*(k-till_now)-1);
            cout << ans << endl;
            return;
        }
        till_now += it;
        p*=2;
    }
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