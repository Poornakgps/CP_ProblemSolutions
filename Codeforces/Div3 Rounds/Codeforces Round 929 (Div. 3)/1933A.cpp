#include"../../../template.h"

void solve(){ 
 
    ll n;
    cin >> n;
    ll a[n];
    ll ans=0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        ans+=(abs(a[i]));
    }
    cout << ans << endl;
 
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
