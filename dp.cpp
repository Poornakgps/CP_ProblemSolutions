#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll dp[205][205], arr[205];
ll n;

// Recursive function to calculate the maximum score
ll rec(int i, int j) {
    if (i > j) {
        return 0; // If there are no balloons to burst, the score is 0
    }
    if (dp[i][j] != -1) {
        return dp[i][j]; // Return the already calculated value
    }

    ll max_score = 0;

    for (int k = i; k <= j; k++) {
        ll left_score = rec(i, k - 1);
        ll right_score = rec(k + 1, j);

        // Calculate the score when bursting the k-th balloon
        ll score = (i > 0 ? arr[i - 1] : 1) * arr[k] * (j < n - 1 ? arr[j + 1] : 1);

        // Maximize the score
        max_score = max(max_score, score + left_score + right_score);
    }

    return dp[i][j] = max_score; // Store and return the maximum score
}

void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0, n - 1) << endl; // Start the recursion with the full array
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
