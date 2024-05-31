#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ss second
#define ff first
#define mod 998244353

#define size(x) (int)(x).size()
using namespace std;

/*********************************************BROKEN********************************************************/
// https://codeforces.com/contest/1398/problem/C
void solve(){

    ll n;
    cin>>n;
    string s;
    cin>>s;

    map<ll,ll> mp;
    mp[0]=1;
    ll curr=0, ans=0;
    for(int i=0; i<n; i++){
        curr+= (ll)(s[i]-'0');
        ll x= curr-i-1;
        ans+= mp[x];
        mp[x]++;
    }
    cout<<ans<<endl;
}
int main(){

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}