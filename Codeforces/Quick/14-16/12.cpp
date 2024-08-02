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
#define rev(v) reverse(v.begin(), v.end())
#define endl() cout << endl

/***************************************C-H-A-O-S**************************************/

// https://codeforces.com/contest/1389/problem/B

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--) {
        ll n, k, z;
        cin >> n >> k >> z;

        ll arr[n];
        fill(arr);

        ll ans = arr[0], pref = arr[0];
        ll mx = arr[0];
        for(int i=1; i<=k; i++){
            mx = max(mx, arr[i]+arr[i-1]);
            ll re = min(z, (k-i+1)/2);
            ans = max(ans, pref + re*mx);
            pref = pref + arr[i];
        }
        ans = max(ans, pref);
        cout<<ans<<endl;
    }
    return 0;
}