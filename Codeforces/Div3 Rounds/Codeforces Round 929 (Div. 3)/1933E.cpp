#include"../../../template.h"


void solve(){ 
 
    ll n, q;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll pref[n+1]={};
    for(ll i = 0; i < n; i++){
        pref[i+1] = pref[i] + a[i];
    }
 
    cin >> q;
    while(q--){
        ll l, u;
        cin >> l >> u;
        u = u + pref[l-1];
        auto it = lower_bound(pref, pref+n+1, u)- pref;
        // cout<<it<<" "<<u<< " ";
        // cout<<pref[it]-pref[it-1]<<" "<<(u - pref[it-1])<<" "<<pref[it]<<" "<<u<<" "; 
        if(it==n+1 || (it!=n+1 &&  (pref[it]<=u || (pref[it]-pref[it-1])/2 + (pref[it]-pref[it-1])%2  <=(u - pref[it-1])))){
            cout << min(1ll*it, n) << " ";
        }
        else{
            cout << max(1ll*it-1ll, l) << " ";
        }
    }
    endl();
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