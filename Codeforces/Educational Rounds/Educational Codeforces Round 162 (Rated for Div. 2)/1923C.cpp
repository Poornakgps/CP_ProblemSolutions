#include "../../template.h"

void solve(){
 
    ll n,q;
    cin>>n>>q;
    ll a[n];
    rep(i,0,n,1) cin>>a[i];
    ll pref[n+1]={}, pre_sum[n+1]={};
    rep(i,1,n+1,1) pref[i]=pref[i-1]+(a[i-1]==1);
    rep(i,1,n+1,1) pre_sum[i]=pre_sum[i-1]+a[i-1];
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll ones = pref[r]-pref[l-1];
        ll sum=pre_sum[r]-pre_sum[l-1] - 2*ones;
        if(l==r){
            cout<<"NO\n";
            continue;
        }
        //cout<<sum<<" \n";
        if(sum>=(r-l+1 -ones))
            cout<<"YES\n";
        else cout<<"NO\n";
 
    }
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