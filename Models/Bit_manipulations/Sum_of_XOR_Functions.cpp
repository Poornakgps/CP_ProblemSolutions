#include "../../template.h"



void solve(){
    ll n;
    
    in(n);
    ll arr[n];
    for (int i= 0; i< n; i++)
        in(arr[i]);
    
    ll ans= 0;    
    for (int bit= 0; bit< 30; bit++) {
        ll cur= 0;
        vector<ll> cnt(2);   // for even and odd cnt
        vector<ll> sum_ind(2); //       ||
        cnt[0]= 1;
        ll x= 0;
        for (int i = 0; i < n; i++) {
            x^= ((arr[i]>>bit)&1);
            ll s= mul(cnt[x^1], (i+1), mod_9);
            add(cur, sum(s, -sum_ind[x^1], mod_9), mod_9);
            cnt[x]++;   
            add(sum_ind[x], i+1, mod_9);
        }      
        add(ans, mul((1<<bit), cur, mod_9), mod_9);
    }
    cout<<ans<<endl;
}

int main() {

    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    
    while(t--){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}