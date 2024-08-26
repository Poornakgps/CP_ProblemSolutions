#include <bits/stdc++.h>

using namespace std;

int n, k;
map<char, char> mp;
string s;

// Memoization table
int dp[1002][1002][26];

int rec(int i, int lft, char prev) {
    if (i == n) {
        return 0;
    }
    if(lft<0){
        return INT_MIN;
    }

    if (dp[i][lft][prev - 'A'] != -1) {
        return dp[i][lft][prev - 'A'];
    }

    int ans = 0;


        // Try all possible character changes
    ans = max({
        rec(i + 1, lft - (mp['A'] != prev), mp['A']),
        rec(i + 1, lft - (mp['B'] != prev), mp['B']),
        rec(i + 1, lft - (mp['C'] != prev), mp['C'])
    });
    

    // Add score for the current position based on the previous character
    if (prev == mp['A']) {
        ans += (s[i] == mp['B']);
    } else if (prev == mp['B']) {
        ans += (s[i] == mp['C']);
    } else if (prev == mp['C']) {
        ans += (s[i] == mp['A']);
    }

    return dp[i][lft][prev - 'A'] = ans;
}

string res;
void generate(int i,int left ,char prev){
    if(i==n)
    return;
    if(left <0) return;

    int t=max({
        rec(i + 1, left  - (mp['A'] != prev), mp['A']),
        rec(i + 1, left  - (mp['B'] != prev), mp['B']),
        rec(i + 1, left  - (mp['C'] != prev), mp['C'])
    });
    cout<<i<<" "<<t<<" "<<rec(i + 1, left  - (mp['A'] != prev), mp['A'])<<" "<<rec(i + 1, left  - (mp['B'] != prev), mp['B'])<<" "<<rec(i + 1, left  - (mp['C'] != prev), mp['C'])<<endl;
    if(t==rec(i + 1, left  - (mp['A'] != prev), mp['A'])){
        
        generate(i + 1, left - (mp['A'] != prev), mp['A']);
        res+=mp['A'];
    }
    else if(t==rec(i + 1, left  - (mp['B'] != prev), mp['B'])){
        
        generate(i + 1, left  - (mp['B'] != prev), mp['B']);
        res+=mp['B'];
    }else{
        
        generate(i + 1, left  - (mp['C'] != prev), mp['C']);
        res+=mp['C'];
    }
    // cout<<res<<" "<<i<<endl;
    return;
}


void solve() {
    cin >> n >> k;
    cin >> s;

    memset(dp, -1, sizeof(dp));
    
    int ans = 0;
    mp['A'] = 'P'; // Mapping for characters 'a', 'b', 'c'
    mp['B'] = 'R';
    mp['C'] = 'S';

    for (char c : {'A', 'B', 'C'}) {
        ans = max(ans, rec(0, k, mp[c]));
    }
    cout << ans << endl;
    res="";

    if(ans==rec(0, k, mp['A'])){
        generate(0,k,mp['A']);
    }else if(ans==rec(0, k, mp['B'])){
        generate(0,k,mp['B']);
    }else{
        generate(0,k,mp['C']);
    }

    cout<<res<<endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}