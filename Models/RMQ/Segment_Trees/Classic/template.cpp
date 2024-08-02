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
#define vi vector<ll>
#define fill(v) for(auto& i: v) cin>>i;
#define has(c, x) {return c.find(x)!=c.end();}
#define pr(v) for(auto i: v) cout<<i<<" "; cout<<endl;
#define pr1(v, i) for(auto j: v) cout<<j[i]<<" "; cout<<endl; 
#define del(s, x) if(s.find(x)!=s.end()) s.erase(s.find(x)) 
#define show(x) cout<<#x<<": "<<x<<" ";
#define rev(v) reverse(v.begin(), v.end())
#define endl() cout << endl
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 200005
#define N_LMT 100001

/***************************************C-H-A-O-S**************************************/

void solve() {

    ll n, k;
    cin >> n >> k;

    vector<pair<ll,ll>> v(n);
    rep(i, 0, n, 1) {
        cin >> v[i].ff;
    }
    for(auto &i : v){
        cin>>i.ss;
    }
    sort(all(v));

    ll ans = 0;
    ll l = 0, r = 1e9;

    while(l<=r){
        ll m = (l+r)/2;
        ll cnt = 0;
        bool ok = false;
        ll k1 = k;
        ll ans1 = 0;
        for(auto i: v){
            ll t = (i.ff - m)/i.ss;
            // cout<<t<<" "<<m<<endl;
            t = min(t, k1);
            // cout<<t<<endl;
            ans1 += (t*i.ff - (t*(t-1)*i.ss)/2);
            k1 -= t;
            if(k1<=0){
                ok = true;
                break;
            }
        }
        // cout<<m<<" "<<ans1<<endl;
        cout<<m<<endl;
        ans = max(ans, ans1);
        // cout<<k1<<endl;
        if(k1<=0){
            
            l = m+1;
        }
        else{
            r = m-1;
        }
    }

    // endl();
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    // pre();
    while (t--) {
        solve();
    }
    return 0;
}
