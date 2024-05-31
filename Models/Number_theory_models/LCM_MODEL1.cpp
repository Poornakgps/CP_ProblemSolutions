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
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 200005

/***************************************C-H-A-O-S**************************************/
// :(
// https://codeforces.com/problemset/problem/1977/C

vector<ll> get_factors(ll n){
    vector<ll> v;
    for(int i=1; i*i<=n; i++ ){
        if(n%i==0){
            v.pb(i);
            if(i!=n/i)
                v.pb(n/i);
        }   
    }
    return v;
}

void solve(){

    ll n;
    cin >> n;
    vector<ll> v(n);

    ll l = 1, mx = -1;
    map<ll,ll> in;
    for(auto &i: v) {
        cin >> i, in[i]++, mx = max(mx, i);
    }
    sort(all(v));

    if(n==1){
        cout << 0 << endl;
        return;
    }
    for(int i=0; i<n; i++){
        l = lcm(l, v[i]);
        if(l>mx){
            cout<<n<<endl;
            return;
        }
    }

    vector<ll> mx_factor = get_factors(l);
    rev(mx_factor);

    ll ans = 0;

    for(auto i: mx_factor){
        ll cnt = 0, curr_lcm = 1;
        if(in[i]){
            continue;
        }
        vector<ll> sub_factors = get_factors(i);

        for(auto j: sub_factors){
            cnt += in[j];  
            if(in[j]){
                curr_lcm = lcm(curr_lcm, j);
            }
        }
        if(ans<cnt && curr_lcm==i){
            ans = cnt;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}