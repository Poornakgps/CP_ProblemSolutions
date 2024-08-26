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

string s;
ll n;
vector<vector<ll>>dp; //dp[i][j]- gives  no.of valid seq. we can form given that till index i depth is j
//depth= no.of close brackets still need to be inserted to make it regular

ll rec(ll i,ll depth){
    if(depth<0)return 0;
    if(i==n){
        if(depth==0)return 1;
        return 0;
    }
    if(dp[i][depth]!=-1)return dp[i][depth];
    // return 1;
    ll ans=0;
    if(s[i]=='('){
        ans+=rec(i+1,depth+1)%mod;
    }
    else if(s[i]==')'){
        ans+=rec(i+1,depth-1)%mod;
    }
    else{
        ans+=rec(i+1,depth+1)%mod;
        ans+=rec(i+1,depth-1)%mod;
    }
    return dp[i][depth]=(ans%mod+mod)%mod;
}
void solve(){
    s.clear();
    dp.clear();
    cin>>s;
    if(s.length()%2){
        cout<<0<<endl;
        return;
    }
    n=s.length();
    dp.resize(n+1,vector<ll>(n+1,-1));

    cout<<rec(0,0)<<endl;
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