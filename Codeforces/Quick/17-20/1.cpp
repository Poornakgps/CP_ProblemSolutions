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

// https://codeforces.com/contest/1672/problem/D

void solve() {

    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    map<ll, ll> shifts;
    rep(i, 0, n, 1) cin >> a[i];
    rep(i, 0, n, 1) cin >> b[i];

    ll l = n-1, r = n-1;
    ll preva = -1, prevb = -1;
    while(l>=0 && r>=0){
        if(a[l]== b[r]){
            preva = a[l];
            l--;
            r--;
        }
        else{
            if(preva == b[r]){
                shifts[preva]++;   
                r--;
            }
            else{
                while(l>=0 && shifts[a[l]] && a[l]!= b[r] ){
                    shifts[a[l]]--;
                    l--;
                }
                if(l>=0 && a[l]==b[r]){
                    preva = a[l];
                    l--;
                    r--;
                    continue;
                }
                cout << "NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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