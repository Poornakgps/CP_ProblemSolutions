#include<bits/stdc++.h>
using namespace std;

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


int main(){

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}