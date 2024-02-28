#include"../../../template.h"

void f(ll arr_unique[], ll arr[], ll a[], ll n, vector<ll> &ans, bool isReversed) {
    for(int i=1; i<=n; i++){
        auto it = upper_bound(arr, arr + n + 1, arr[i] + a[i]) - arr;
        if(it<n+1){
            ll l= arr_unique[i+1], r= arr_unique[it], cur= arr_unique[i];
            if((arr[it]-arr[i]>a[i] && (r-l>0 || i+1==it) )){
                int index = isReversed ? n-i+1 : i;
                ans[index] = min(ans[index], (ll)(it-i));
            }
            else{
                auto next = upper_bound(arr_unique, arr_unique + n + 1, r)-arr_unique;
                if(next!=n+1){
                    int index = isReversed ? n-i+1 : i;
                    ans[index] = min(ans[index], (ll)(it-i + ((next-it))));
                }
            }
        }  
    }
}
 
void solve(){
 
    ll n;
    cin >> n;
    ll a[n+2];
    a[0]=0;
    a[n+1]=0;
    rep(i, 1, n+1, 1) cin >> a[i];
    ll suf[n+1]={}, pref[n+1]={}, suf_unique[n+1]={}, pref_unique[n+1]={};
    vector<ll> ans(n+2, 1e9);
    for(ll i = 1; i <= n; i++){
        suf[i] = suf[i-1] + a[n-i+1];
        suf_unique[i] = suf_unique[i-1] + (a[n-i+1] != a[n-i+2]);
    }
    for(ll i = 1; i <=n; i++){
        pref[i] = pref[i-1] + a[i];
        pref_unique[i] = pref_unique[i-1] + (a[i] != a[i-1]);
    }
 
    f(pref_unique, pref, a, n, ans, 0);
    reverse(a, a+n+2);
    f(suf_unique, suf, a, n, ans, 1);
 
    for(ll i = 1; i <= n; i++){
        if(ans[i]==1e9){
            ans[i] = -1;
        }
        cout<<ans[i]<<" ";
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