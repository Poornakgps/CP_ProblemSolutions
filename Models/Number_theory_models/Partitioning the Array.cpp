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


// https://codeforces.com/problemset/problem/1920/C

void solve() {

    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];

    vector<ll> factors;

    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            factors.pb(i);
            if(i!=n/i)
                factors.pb(n/i);
        }
    }
    ll ans=0;
    for(auto it: factors){
        bool ok = true;
        ll g = 0;
        for(int i=0; i<it; i++){
            
            for(int j = i+it; j<n; j+=it){
                if(__gcd(g, abs(a[j]-a[j-it]))==1){
                    ok = false;
                    break;
                }
                g = __gcd(g, abs(a[j]-a[j-it]));
            }
            if(!ok)
                break;
        }
        if(ok){
            ans++;
        }
    }
    cout<<ans<<endl;

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