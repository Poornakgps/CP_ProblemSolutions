#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

ll maxProduct(vector<ll>& nums) {
    ll n = nums.size(), ans = LLONG_MIN, mx = 1, mn = 1;
    for (int i = 0; i < n; i++) {
        ll t = mn;
        mn = min({nums[i], mn*nums[i], mx*nums[i]});
        mx = max({nums[i], mx*nums[i], t*nums[i]});
        ans = max(ans, mx);
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    cout << maxProduct(a) << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
