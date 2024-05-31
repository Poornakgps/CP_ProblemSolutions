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

// https://codeforces.com/contest/1459/problem/C
// From basic properties of GCD we know that GCD(x,y)=GCD(x−y,y)
// . The same applies for multiple arguments: GCD(x,y,z,…)=GCD(x−y,y,z,…)
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n), u(m);
    fill(v);
    fill(u);
    sort(all(v));
    ll g = v[n-1]-v[0];
    for(int i=n-2; i>=1; i--){
        g = __gcd(g, v[i]-v[0]);
    }
    for(int i=0; i<m; i++){
        cout<<__gcd(v[0]+u[i], g)<<" ";
    }
    endl();
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