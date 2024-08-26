#include <bits/stdc++.h>

using namespace std;

int n, W;
int a[3003];
int w[3003];
int dp[3003][3003];

// Form 1

int rec(int i, int wt) {
    // BaseCase
    if (i == n) return 0;

    // Cache Check
    if (dp[i][wt] != -1) return dp[i][wt];

    // Transition
    int ans = rec(i + 1, wt);
    if (wt >= w[i]) {
        ans = max(ans, rec(i + 1, wt - w[i]) + a[i]);
    }

    // Save and return
    return dp[i][wt] = ans;
}

void solve() {
    cin >> n >> W;

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> w[i];

    cout << rec(0, W) << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
