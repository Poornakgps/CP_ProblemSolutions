#include<bits/stdc++.h>
// https://codeforces.com/contest/1946/problem/D
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
#define __builtin_popcount(x) count_ones(x)
#define endl() cout<<endl
#define Yes() cout<<"YES\n"
#define No() cout<<"NO\n"

ll tut(vector<ll> a, ll x){
    ll n = a.size();

    ll curr_xor=0, ans=0;

    for(int i=0; i<n; i++){

        curr_xor ^= a[i];

        if( (curr_xor | x ) == x){
            curr_xor = 0;
            ans++;
        }
        else{
            if(i==n-1){
                return -1;
            }
        }
    }
    return ans;
}

void solve(){ 

    ll n, x;
    cin >> n >> x;

    ll xor_all = 0;
    vector<ll> a(n);
    rep(i, 0, n, 1) cin >> a[i], xor_all ^= a[i];

    if(xor_all > x){
        cout << -1 << endl;
        return; 
    }

    ll ans = tut(a, x);

    for(int i=29; i>=0; i--){
        if( (x>>i) & 1 ){
            ll y = (x ^ (1<<i));

            for(int j = i-1; j >= 0; j--){
                if( ((y>>j) & 1) == 0){
                    y ^= (1<<j);
                }
            }
            ans = max(ans, tut(a, y));
        }
    }

    cout << ans << endl;
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