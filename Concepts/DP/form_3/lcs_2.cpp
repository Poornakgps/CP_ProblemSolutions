#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll longestCommonSubsequence(string &s1, string &s2) {
    ll n = s1.length();
    ll m = s2.length();

    // Create a 2D dp array initialized to 0
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    // Bottom-up calculation of LCS
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // LCS length is stored in dp[n][m]
    return dp[n][m];
}

void solve() {
    string s;
    cin >> s;

    // Reverse the input string to find LCS with itself
    string t = s;
    reverse(t.begin(), t.end());

    // Calculate the LCS length
    ll lcs_length = longestCommonSubsequence(s, t);

    // Output the minimum number of insertions needed to make the string a palindrome
    cout << s.length() - lcs_length << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// recursive with printing soln
// int dp[3005][3005];
// string s, t;
// int n, m;

// int lcs(int i, int j){
//     if(i==n || j==m){
//         return 0;
//     }
//     // cout<<i<<" "<<j<<endl;
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }

//     int ans = 0;

//     if(s[i]==t[j]){
//         ans = 1 + lcs(i+1, j+1);
//     }
//     else{
//         ans = max(lcs(i+1, j), lcs(i, j+1));
//     }
//     return dp[i][j] = ans;
// }

// vector<char> solution;

// void generate(int i, int j) {
//     // BaseCase
//     if (i == n || j==m) return;

//     // Transition
//     if(s[i]==t[j]){
//         solution.push_back(t[j]);
//         generate(i+1, j+1);
//     }
//     else{
//         int lft = dp[i+1][j];
//         int rgt = dp[i][j+1];
//         if(lft>rgt){
//             generate(i+1, j);
//         }
//         else{
//             generate(i, j+1);
//         }
//     }
// }
// void solve() {

//     cin>>s>>t;
//     n = s.size(), m = t.size();
//     memset(dp, -1, sizeof(dp));
//     int lcs_length = lcs(0, 0);

//     // cout<<lcs_length<<endl;

//     generate(0, 0);

//     for(auto it: solution){
//         cout<<it;
//     }
// }

// signed main(){
//     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//     ll t=1;
//     while (t--){
//         solve();
//     }
// }