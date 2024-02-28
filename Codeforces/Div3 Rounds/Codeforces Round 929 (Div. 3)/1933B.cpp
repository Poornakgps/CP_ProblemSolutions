#include"../../../template.h"

void solve(){ 
 
    ll n;
    cin >> n;
    ll a[n];
    ll ans=0;
    map<ll,ll> mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        ans+=(abs(a[i]));
        mp[a[i]%3]++;
    }
    if(ans%3==0){
        cout<<0<<endl;
        return;
    }
    if(ans%3==1){
        if(mp[1]>0){
            cout<<1<<endl;
            return;
        }
        if(mp[2]>1){
            cout<<2<<endl;
            return;
        }
        cout<<2<<endl;
        return;
    }
    if(ans%3==2){
        cout<<1<<endl;
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