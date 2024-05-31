#include <bits/stdc++.h>
 
using namespace std;
 
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
#define pii pair<int, int>
typedef long long ll;
#define fill(v) for(auto& i: v) cin>>i;
#define has(c, x) {return c.find(x)!=c.end();}
#define pr(v) for(auto i: v) cout<<i<<" "; cout<<endl;
#define pr1(v, i) for(auto j: v) cout<<j[i]<<" "; cout<<endl; 
#define del(s, x) if(s.find(x)!=s.end()) s.erase(s.find(x)) 
#define show(x) cout<<#x<<": "<<x<<" ";
#define rev(v) reverse(v.begin(), v.end())
#define endl() cout << endl
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"

/***************************************C-H-A-O-S**************************************/
// https://codeforces.com/contest/1305/problem/C
void solve(){
            
    ll n, m;    
    cin >> n >> m;

    vector<ll> a(n);
    fill(a);

    if(n>m){
        cout << 0 << endl;
        return;
    }

    ll ans=1;

    rep(i, 0, n, 1){
        rep(j, i+1, n, 1){
            ans = (ans * abs(a[i]-a[j]))%m;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}