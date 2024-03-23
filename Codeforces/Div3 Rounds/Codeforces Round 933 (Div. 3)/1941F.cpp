#include<bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for(ll i = a; i < (b); i+=c)
#define all(x) begin(x), end(x)
#define pii pair<ll, ll>
typedef long long ll;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define count_ones(x) __builtin_popcount(x) 
#define endl() cout<<endl
#define Yes() cout<<"YES\n"
#define No() cout<<"NO\n"


/************************** 1000000007 ****************************/

void solve(){

    ll n, m, k;

    cin >> n >> m >> k;

    vector<ll> a(n);

    for(ll i = 0; i < n; i++){ cin >> a[i]; }

    vector<ll> d(m);

    for(ll i = 0; i < m; i++){ cin >> d[i]; }

    vector<ll> f(k);

    for(ll i = 0; i < k; i++){ cin >> f[i]; }

    sort(all(d)), sort(all(f));

    ll mx = 0, mx2=0;
    for(int i=1; i<n; i++){
        if(mx <= a[i] - a[i-1]){
            mx2= mx;
            mx = a[i] - a[i-1];
        }
        else{
            mx2 = max(mx2 , a[i] - a[i-1]);
        }
    }
    if(mx == mx2){
        cout << mx <<endl;
        return;
    }
    ll l = 0, r = 0;

    for(int i=1; i<n; i++){
        if(a[i]-a[i-1] == mx){
            l = a[i-1], r = a[i];
            break;
        }
    }
    ll ans = mx;
    for(int i = 0; i < m; i++ ){

        ll req = l + mx/2 - d[i] ;

        auto it = lower_bound(all(f), req) - f.begin();
        if(it==k){
            it--;
        }

        if(it>=0){
            ll x = d[i] + f[it];
            ans = min(ans , max(x-l, r-x));
            if(it-1>=0){
                x = d[i] + f[it-1];
                ans = min(ans, max(x - l, r - x));
            }
        }
    }
    cout<<max(mx2 , ans)<<endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
