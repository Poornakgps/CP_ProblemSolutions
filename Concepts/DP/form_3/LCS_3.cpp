#include<bits/stdc++.h>
using namespace std;
#define ll long long
// Form 2

vector<vector<vector<ll>>> dp;

ll rec(string &s1,string &s2,string &s3,ll i,ll j,ll k){

    if(i==s1.length()||j==s2.length()||k==s3.length()){
        return 0;
    }
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    ll ans=0;
    if((s1[i]==s2[j])&&(s2[j]==s3[k])){
        ans=1+rec(s1,s2,s3,i+1,j+1,k+1);
    }
    ans=max(ans,rec(s1,s2,s3,i+1,j,k));
    ans=max(ans,rec(s1,s2,s3,i,j+1,k));
    ans=max(ans,rec(s1,s2,s3,i,j,k+1));

    return dp[i][j][k]=ans;
}

void solve(){
    string s1,s2,s3;

    cin>>s1>>s2>>s3;
    dp.clear();
    dp.assign(s1.length(),vector<vector<ll>> (s2.length(),vector<ll> (s3.length(),-1)));

    cout<<rec(s1,s2,s3,0,0,0)<<endl;
    return ;
}

ll longestCommonSubsequenceOfThree(string &s1, string &s2, string &s3) {
    ll n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
    
    // Initialize a 3D dp array to store the LCS length for substrings of s1, s2, s3
    vector<vector<vector<ll>>> dp(n1 + 1, vector<vector<ll>>(n2 + 1, vector<ll>(n3 + 1, 0)));

    // Bottom-up calculation of LCS for three strings
    for (ll i = 1; i <= n1; i++) {
        for (ll j = 1; j <= n2; j++) {
            for (ll k = 1; k <= n3; k++) {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                    // If characters match, add 1 to the LCS of the previous substrings
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                } else {
                    // Otherwise, take the maximum by excluding one character from one of the strings
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
    }

    // LCS length for the entire strings is stored in dp[n1][n2][n3]
    return dp[n1][n2][n3];
}


int main(){

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}