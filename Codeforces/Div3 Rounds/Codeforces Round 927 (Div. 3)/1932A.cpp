#include <bits/stdc++.h>
 
using namespace std;


void solve(){
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; i++) {
        ans += (s[i] == '@');
        if (s[i] == '*' && s[i - 1] == '*')
            break;
    }
    cout << ans << "\n";
}
int main() {
 
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}