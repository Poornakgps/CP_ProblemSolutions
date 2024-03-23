// DP + Data Structures
// https://codeforces.com/contest/1932/problem/F
#include "../../template.h"


void solve() {

    ll n, m;
    cin >> n >> m;

    vector<ll> start_points[n+1];

    ll end_points[n+1]={};

    vector<ll> dp(n+1);

    for(int i=0; i<m; i++){

        ll x, y;
        cin >> x >> y;

        start_points[y].pb(x);

        end_points[x]++;  // number of end_points
    }

    multiset<ll> s;

    for(int i=1; i<=n; i++){

        dp[i] = dp[i-1];

        for(int j = 0; j<end_points[i]; j++){
            s.insert(i);
        }

        if(!s.empty()){
            dp[i] = max(dp[i], (dp[*s.begin()-1]+ (ll)s.size())); 
        }

        for(auto x: start_points[i]){
            s.erase(s.find(x));
        }
    }
    cout<< dp[n] << endl;
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