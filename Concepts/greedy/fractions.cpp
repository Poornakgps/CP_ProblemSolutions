#include<bits/stdc++.h>

using namespace std;
#define ll long long


pair<ll,ll> red_frac(ll a, ll b){
    if(a==0 || b==0){
        return {(a!=0), (b!=0)};
    }

    ll x = __gcd(a, b);
    return {a/x, b/x};
}

int main(){

    int n;
    cin>>n;

    ll a[n];
    map<pair<ll,ll> , ll> mp;
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        ans+= mp[red_frac(a[i], i)];
        mp[red_frac(a[i], i)]++;
    }
    cout<<ans<<endl;
}