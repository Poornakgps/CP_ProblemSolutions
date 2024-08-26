#include <bits/stdc++.h>

// Form 1
using namespace std;

int n, W;
int a[3003];
int w[3003];
int dp[3003][3003];

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

vector<int> solution;

void generate(int i, int wt) {
    // BaseCase
    if (i == n) return;

    // Transition
    int dont_take = rec(i + 1, wt);

    if (wt >= w[i]) {
        // Take
        int take = rec(i + 1, wt - w[i]) + a[i];
        if (take > dont_take) {
            solution.push_back(i);
            generate(i + 1, wt - w[i]);
        } else {
            generate(i + 1, wt);
        }
    } else {
        // Can't take
        generate(i + 1, wt);
    }
}

void solve() {
    cin >> n >> W;

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> w[i];

    cout << rec(0, W) << endl;

    solution.clear();  // Clear solution vector before generating
    generate(0, W);

    cout << solution.size() << endl;
    for (auto i : solution) cout << i << " ";
    cout << endl; // Make sure to print a newline after the solution
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
