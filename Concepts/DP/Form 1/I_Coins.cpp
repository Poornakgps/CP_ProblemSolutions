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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    
    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    // Memoization table
    vector<vector<double>> memo(n + 1, vector<double>(n + 1, -1));
    
    double ans = 0;
    // We need to sum probabilities of having more than n/2 heads
    for (int i = (n + 1) / 2; i <= n; i++) {
        ans += recursive_dp(n, i, p, memo);
    }
    
    cout << ans << '\n';
    
    return 0;
}
