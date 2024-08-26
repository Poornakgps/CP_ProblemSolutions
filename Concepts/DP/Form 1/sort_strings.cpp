#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main() {
   IOS
   int t;
   cin >> t;
   while(t--) {
       int n;
       cin >> n;
       int c[n];
       for (int i = 0; i < n; ++i) {
           cin >> c[i];
       }
       string s[n];
       string rev[n];
       for (int i = 0; i < n; ++i) {
           cin >> s[i];
           rev[i] = s[i];
           reverse(rev[i].begin(), rev[i].end());
       }
       int dp[n][2];
       dp[0][0] = 0;
       dp[0][1] = c[0];
       for (int i = 1; i < n; ++i) {
           dp[i][0] = dp[i][1] = 1e18;
           if(s[i-1] <= s[i]){
               dp[i][0] = min(dp[i][0], dp[i-1][0]);
           }
           if(rev[i-1] <= s[i]){
               dp[i][0] = min(dp[i][0], dp[i-1][1]);
           }
           if(s[i-1] <= rev[i]){
               dp[i][1] = min(dp[i][1], dp[i-1][0]+c[i]);
           }
           if(rev[i-1] <= rev[i]){
               dp[i][1] = min(dp[i][1], dp[i-1][1]+c[i]);
           }
       }
       int t = min(dp[n-1][0], dp[n-1][1]);
       if (t == (int)1e18)
           t = -1;
       cout << t << "\n";
   }
   return 0;
}
