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

//https://codeforces.com/contest/1970/problem/B2


void solve() {

    ll n;
    cin >> n;
    
    vector<ll> a(n);

    for(auto &x : a) cin >> x;
    cout<<"YES\n";

    cout<<1<<' '<<1<<'\n';

    ll prevx = 1;
    ll ans[n];
    ans[0]=1;
    for(int i=1; i<n; i++){

        if(a[i]==0){
            cout<<i+1<<" "<<1<<'\n';
            prevx = 1;
            ans[i] = i+1;
            continue;
        }

        if(a[i]>=i){
            cout<<i+1<<" "<<a[i]-i+1<<'\n';
            prevx = a[i]-i+1;
            ans[i] = 1;
        }
        else{
            cout<<i+1<<" "<<i; 

            ans[i] = i+1-a[i];
        }
    }
    for(auto x : ans) cout<<x<<' ';
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