#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dp[505][505];

int main() {
   IOS
   int t;
   cin >> t;
   while (t--) {
       int n;
       cin >> n;
       int a[n+2];
       a[0] = 0; a[n+1] = 0;
       for (int i = 1; i <= n; ++i) {
           cin >> a[i];
       }
       for (int i = 0; i <= n + 4; ++i) {
           for (int j = 0; j <= n + 4; ++j) {
               dp[i][j] = 0;
           }
       }
       for (int l = 1; l <= n; ++l) {
           for (int s = 1, e = l; e <= n; ++s, ++e) {
               if(l == 1) dp[s][e] = 1;
               else {
                   dp[s][e] = 1 + dp[s+1][e];
                   if(a[s] == a[s+1])
                       dp[s][e] = min(dp[s][e], 1 + dp[s+2][e]);
                   for (int k = s + 2; k <= e; ++k) {
                       if(a[s] == a[k])
                           dp[s][e] = min(dp[s][e], dp[s+1][k-1] + dp[k+1][e]);
                   }
               }
           }
       }
       cout << dp[1][n] << "\n";
   }
   return 0;
}