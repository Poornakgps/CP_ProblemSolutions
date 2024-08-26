#include<bits/stdc++.h>

using namespace std;

// Form 2

void solve(){
    string s;
    cin>>s;

    int n=s.size();
    int last[26];
    int dp[n+1];

    memset(last,-1,sizeof(last));

    dp[0]=1;

    for(int i=1;i<=n;i++){
        dp[i]=2*dp[i-1];
        if(last[s[i-1]-'a']!=-1){
            dp[i]-=dp[last[s[i-1]-'a']-1];
        }
        last[s[i-1]-'a']=i;
    }
    cout<<dp[n]-1<<endl;
}


int main(){
    int t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}