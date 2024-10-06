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
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define MAXN 300005
#define N_LMT 100001
#define janu main
#define int long long

vector<ll>dv;
int sz, n;
vector<vector<int>> dp;
vector<int> w, a;

void get_divisors(ll n) {
   dv.clear();
    int p = n;
    for (int i = 2; i * i <= p; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
               dv.pb(i);
                n = n / i;
            }
        }
    }
    if (n != 1) {
       dv.pb(n);
    }
    sort(all(dv));
}

int rec(int i, int wt, int prod, int sum) {
    // Base case: if we've processed all elements
    if (i == sz) return prod;

    // Cache check
    if (dp[i][wt] != -1) return dp[i][wt];

    // Option 1: Skip current item
    int ans = rec(i + 1, wt, prod, sum);

    // Option 2: Include current item if the condition is satisfied
    if (sum - dv[i] + dv[i] * prod <= wt) {
        ans = max(ans, rec(i + 1, wt - dv[i] * prod, prod * dv[i], sum - dv[i]));
    }

    // Save and return the result
    return dp[i][wt] = ans;
}

vector<int> solution;

void solve() {
    ll p;
    cin >> p;

    get_divisors(p);

    if (p == 1) {
        cout << 41 << " ";
        for (int i = 0; i < 41; i++) {
            cout << 1 << " ";
        }
        return;
    }

    if (dv.size() == 0) {
        if (p == 41) {
            cout << 1 << " " << 41;
        } else {
            cout << -1;
        }
        return;
    }

    ll sum = 0;
    for (auto it :dv) {
        sum += it;
    }
    if (sum > 41) {
        cout << -1;
        return;
    }

    sz = dv.size();
    vector<int> p_result;
    int req = 41;
    while (dv[dv.size() - 1] != 1) {
        dp.assign(sz + 1, vector<int>(req + 1, -1));
        int ans = rec(0, req, 1, sum);

        p_result.pb(ans);
        req -= ans;
        cout<<req<<" "<<ans<<" "<<" \n";
        cout<<sum<<endl;
        for(auto &it: dv){
            if(ans%it==0){
                sum-=(it-1);
                ans = ans/it;
                it = 1;
            }
        }
        cout<<sum<<endl;
        sort(all(dv));
        for(auto it: dv){
            cout<<it<<" ";
        }
        cout<<endl;
        // exit(0);
    }
    for (int i = 0; i < 41 - sum; i++) {
        p_result.pb(1);
    }
    sort(all(p_result));
    // cout << p_result.size() << " ";
    // for (auto it : p_result) {
    //     cout << it << " ";
    // }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    int i = 1;
    while (t--) {
        // cout << fixed << setprecision(12) << "Case #" << i << ": ";
        solve();
        cout << endl;
        i++;
    }

    return 0;
}
