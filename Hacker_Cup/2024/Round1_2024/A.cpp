#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double solve() {
    ll n;
    cin >> n;
    vector<pair<double, double>> rng(n);

    for (auto& it : rng) {
        cin >> it.first >> it.second;
    }

    double max_lower = 0, min_upper = 1e9;
    for (ll i = 0; i < n; i++) {
        double l = rng[i].first;
        double u = rng[i].second;
        if (l != 0) {
            min_upper = min(min_upper, 1.00*(i+1) / l);
        }
        if (u != 0) {
            max_lower = max(max_lower, 1.00*(i+1) / u);
        }
    }

    if (max_lower > min_upper) {
        return -1; 
    }
    return max_lower;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    int i = 1;
    while (t--) {
        cout << fixed << setprecision(12) << "Case #" << i << ": " << solve() << endl;
        i++;
    }

    return 0;
}
