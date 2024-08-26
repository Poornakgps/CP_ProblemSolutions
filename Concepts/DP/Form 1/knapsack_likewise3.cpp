#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define fr(i,n) for(i=0;i<n;i++)
#define fr1(i,n) for(i=n-1,i>=0;i--)



ll mod=1000000007;

void solve(){
    ll n,i;
    cin>>n;
    string s;
    cin>>s;
    vector<ll>c(n+1);
    vector<ll> dp(4,0); // it stores min cost so that prefix of len i (of hard) is not formed , so dp[4] gives min. cost so that hard is not formed 
    for(ll i=0;i<n;i++)cin>>c[i];

    for(ll i=0;i<n;i++){
        if(s[i]=='h')dp[0]+=c[i];
        else if(s[i]=='a')dp[1]=min(dp[0],dp[1]+c[i]);  //  in cost to not form "ha" is min. of (either min. cost to not form "h" at all or min cost of not forming "ha"till now +cost of removing a now )
        else if(s[i]=='r')dp[2]=min(dp[1],dp[2]+c[i]);
        else if(s[i]=='d')dp[3]=min(dp[2],dp[3]+c[i]);
    }

    // if(dp[3]==1e17)cout<<0<<endl;
    cout<<dp[3]<<endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}