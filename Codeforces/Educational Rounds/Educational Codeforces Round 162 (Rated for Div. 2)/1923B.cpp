#include"../../../template.h"

void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n],x[n];
    rep(i,0,n,1){
        cin>>a[i];
    }
    ll sum=0;
    map<ll,ll> mp;
    rep(i,0,n,1){
        cin>>x[i];
        mp[abs(x[i])] +=a[i];
        sum+=a[i];
    }
    ll s=0, lft=0;
    for(auto it: mp){
        if((it.ff-s)*k +lft<it.ss){
            No();
            return;
        }
        lft = (it.ff-s)*k + lft - it.ss;
        s=it.ff;
    }
    Yes();
 
} 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}