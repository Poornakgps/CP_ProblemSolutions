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

// constructive + greedy
// https://codeforces.com/problemset/problem/1661/D
void solve() {

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n), c(n);
    for(int i=0; i<n; i++){
        cin >> b[i];
    }

    ll ans = 0, val = k, add = 0, remove = 0;

    for(int i=n-1; i>=k; i--){
        if(a[i] + add >= b[i]){
            add -= remove;
            if(c[i]){
                remove -= c[i];
            }
            continue;
        }
        val = ceil((1.0*(b[i]-a[i]-add))/k);
        add = add + val*k;
        remove += val;
        c[i-k + 1] = val;
        if(c[i]){
            add -= c[i];
            remove -= c[i];
        }
        ans += val;
        add-=(remove);
    }
    ll max_to_remove = 0;

    for(int i=k-1; i>=0; i--){
        a[i] += add;
        add -= remove;
        if(c[i]){
            remove -= c[i];
        }
    }
    for(int i=0; i<k; i++){
        max_to_remove = max(max_to_remove, (ll)(ceil((1.0*(b[i]-a[i]))/(i+1))));
    }
    ans+=max_to_remove;
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}