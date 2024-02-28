#include"../template.h"

/************************** 1000000007 ****************************/

void solve(){

    ll n;
    cin>>n;
    map<ll,ll> mp;

    rep(i,0,n,1){
        ll t;
        in(t);
        mp[t]++;
    }
    ll ans=0;
    ll k=n;
    for (auto it = mp.rbegin(); it != mp.rend(); ++it){
        //cout<<it->ff<<" "<<it->ss<<endl;
        if(it->ss>=2){
            ans+=(it->ss*(it->ss-1))*(it->ss-2)/6;
            ans+=(it->ss*(it->ss-1)/2)*(k-it->ss);
        }
        k= k-it->ss;
    }
    cout<<ans<<endl;
} 

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }

    return 0;
}