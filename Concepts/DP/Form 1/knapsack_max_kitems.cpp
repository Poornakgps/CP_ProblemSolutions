#include <bits/stdc++.h>

// Form 1
using namespace std;

int n, W, k;
int a[3003];
int w[3003];
int dp[100][500][100];

int rec(int i, int wt, int items_left) {

    // max value u can make from 1 to n items with weight wt and items_left items left to be taken

    // BaseCase
    if (i == n) return 0;

    // Cache Check
    if (dp[i][wt][items_left] != -1) return dp[i][wt][items_left];

    // Transition
    int ans = rec(i + 1, wt, items_left);
    if (wt >= w[i] && items_left>0) {
        ans = max(ans, rec(i + 1, wt - w[i]) + a[i], items_left - 1);
    }

    // Save and return
    return dp[i][wt][items_left] = ans;
}

void solve() {
    cin >> n >> W >> k;

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> w[i];

    cout << rec(0, W, k) << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
