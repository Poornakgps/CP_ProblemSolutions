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

// https://codeforces.com/problemset/problem/1419/D2

void solve() {

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x: a) cin>>x;

    sort(all(a));

    ll l = 0, r = n-1, ans=0;

    while(l<=r){
        ll m = (l+r)/2;
        
        ll ind = 0;

        for(int i=m; i<n; i++){
            if(a[ind]<a[i] && i<n-1){
                ind++;
            }
            if(ind>=m) break;
        }
        if(ind>=m){
            ans = m;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    cout<<ans<<endl;
    int ind = 0;
    deque<ll> q;
    for(int i = ans; i<n; i++){
        if(a[ind]<a[i] && ind<ans){
            cout<<a[i]<<" "<<a[ind]<<" ";
            ind++;
        }
        else{
            //cout<<i<<endl;
            q.pb(a[i]);
        }
    }
    sort(all(q), greater<ll>());
    for(auto it: q){
        cout<<it<<" ";
    }
    endl();
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