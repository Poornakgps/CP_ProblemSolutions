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
#define MAXN 100005
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"

/***************************************C-H-A-O-S**************************************/

// https://codeforces.com/contest/1974/problem/E
struct Month {
    ll cost;
    ll happiness;
};

void solve() {
    ll m, x;
    cin >> m >> x;
    
    vector<Month> months(m);
    for (ll i = 0; i < m; ++i) {
        cin >> months[i].cost >> months[i].happiness;
    }

    ll max_happiness_sum = 0;

    for (const auto& month : months) {
        max_happiness_sum += month.happiness;
    }

    vector<vector<ll>> dp(m, vector<ll>(max_happiness_sum + 1, -1));
    dp[0][0] = 0; 
    if(months[0].cost==0){
        dp[0][months[0].happiness] = 0;
    }
    
    for (ll i = 1; i < m; ++i) {

        for (ll j = 0; j < max_happiness_sum; j++) {
            if (dp[i-1][j] == -1){
                continue;
            } 
            else{
                dp[i][j] = max(dp[i][j], dp[i-1][j]+x);
            }

            if(dp[i-1][j]+x>=months[i].cost && j+months[i].happiness<=max_happiness_sum){

                dp[i][j+months[i].happiness] = max(dp[i][j+months[i].happiness], dp[i-1][j]-months[i].cost + x);
            }

        }
        
    }
    ll ans = 0;
    for(int i=max_happiness_sum;i>=0;i--){
        if(dp[m-1][i]>=0){
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}