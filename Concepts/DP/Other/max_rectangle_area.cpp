#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   while(t--) {
       int n, m;
       cin >> n >> m;
       bool grid[n][m];
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < m; ++j) {
               cin >> grid[i][j];
           }
       }
       int dp[n][m];
       memset(dp, 0, sizeof(dp));
       int ans = 0;
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < m; ++j) {
               if(grid[i][j]) {
                   dp[i][j] = j == 0 ? 1 : dp[i][j-1] + 1;
                   int width = dp[i][j];
                   
                   for (int k = i; k >= 0; --k) {
                       width = min(width, dp[k][j]);
                       ans = max(ans, width * (i - k + 1));
                   }
               }
           }
       }
       cout << ans << "\n";
   }
   return 0;
}```
