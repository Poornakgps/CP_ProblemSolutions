#include"../../../template.h"

void solve(){ 
 
    ll n;
    cin>>n;
    map<ll,ll> mp;
    ll g=0;
    for(int i=0; i<n; i++){
        ll x;
        cin>>x;
        mp[x]++;
        g = __gcd(g,x);
    }
    if(mp[g]>1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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