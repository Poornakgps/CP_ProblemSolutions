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

/***************************************C-H-A-O-S**************************************/
//  https://codeforces.com/contest/1350/problem/B
//  O(nlog(n))
void solve(){

    ll n;
    cin >> n;
    vi v(n);
    fill(v);
    ll ans = 1;

    vi dp(n, 1);

    rep(i, 1, n+1, 1){
        for(int j = 2*i ; j<=n; j+=i){
            if(v[j-1] > v[i-1]){
                dp[j-1] = max(dp[j-1], dp[i-1]+1);
            }
        }
        ans = max(ans, dp[i-1]);
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