/*
You are given a non-empty string S consisting of lower case characters. You can change at most K letters to maximise 
the cost. If in the final string, X immediately precedes Y, you get an increase in cost by C. You have to determine 
the maximum cost possible.
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

int k, M_;

string s;

map<pair<char, char>, int> dictionary;

int dp[102][102][26];

int rec(int i, int k, char prev){
    if(i == s.size()){
        return 0;
    }

    if(dp[i][k][prev - 'a']!=-1){
        return dp[i][k][prev - 'a'];
    }

    int ans = -1e18;


    for(char c = 'a'; c <= 'z'; c++){
        if(c!= s[i] && k>0)
            ans = max(ans, dictionary[{prev, c}] + rec(i + 1, k - 1, c));
        else if(c==s[i])
            ans = max(ans, dictionary[{prev, c}] + rec(i+1, k, c));
    }
        
    
    return dp[i][k][prev - 'a'] = ans;
}

void solve(){

    cin >> s >> k;

    cin >> M_;
    dictionary.clear();
    for(int i = 0; i < M_; i++){
        char a, b;
        int c;
        cin >> a >> b >> c;
        dictionary[{a, b}] = c;
    }
    memset(dp, -1, sizeof(dp));

    int ans = -1e18;

    for(char c = 'a'; c<='z'; c++){
        if(s[0]!= c && k>0){
            ans =  max(ans, rec(1, k-1, c));
        }
        else if(s[0] == c){
            ans = max(ans, rec(1, k, c));
        }
    }
    
    cout<<ans<<endl;
}

int32_t main(){

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }
}