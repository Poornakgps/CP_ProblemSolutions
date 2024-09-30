#include <bits/stdc++.h>
using namespace std;

double recursive_dp(int i, int heads, const vector<double>& p, vector<vector<double>>& memo) {
    if (i == 0) {
        // Base case: If no coins are left, the probability is 1 if heads == 0, else it's 0
        return heads == 0 ? 1.0 : 0.0;
    }
    if (memo[i][heads] != -1) {
        return memo[i][heads];
    }
    // Probability of getting `heads` heads after `i` coins
    double prob = 0;
    // Case 1: This coin is a head
    if (heads > 0) {
        prob += recursive_dp(i - 1, heads - 1, p, memo) * p[i - 1];
    }
    // Case 2: This coin is a tail
    prob += recursive_dp(i - 1, heads, p, memo) * (1 - p[i - 1]);
    
    return memo[i][heads] = prob;
}


void iterative() {
    cout << fixed << setprecision(15);
    int n;
    cin >> n;

    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));

    // Base case: If no coins are left, the probability of getting 0 heads is 1
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int heads = 0; heads <= i; heads++) {
            // If this coin is a head
            if (heads + 1 <= n) {
                dp[i + 1][heads + 1] += dp[i][heads] * p[i]; // Move to the next coin with one more head
            }
            // If this coin is a tail
            dp[i + 1][heads] += dp[i][heads] * (1 - p[i]); // Stay at the same number of heads
        }
    }

    double ans = 0;
    for (int heads = (n + 1) / 2; heads <= n; heads++) {
        ans += dp[n][heads];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    iterative();
    return 0;
    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<vector<double>> memo(n + 1, vector<double>(n + 1, -1));
    
    double ans = 0;
    for (int i = (n + 1) / 2; i <= n; i++) {
        ans += recursive_dp(n, i, p, memo);
    }
    
    cout << ans << '\n';
    
    return 0;
}
