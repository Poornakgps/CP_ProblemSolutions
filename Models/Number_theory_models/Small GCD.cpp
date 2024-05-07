#include "../../template.h"

void solve(){
    ll n;
    cin>>n;

    ll arr[n];
    rep(i,0,n,1) cin>>arr[i];

    sort(arr,arr+n);

    vector<ll> dp(100005), freq(100005);

    rep(i, 0, n, 1) {
        for(int j=1; j*j<= arr[i]; j++) {
            if(arr[i]%j == 0) {
                dp[j]+= freq[j]*(n-1-i); // pre calculation for each divisor of int
                freq[j]++;
                if(j != arr[i]/j) {
                    dp[arr[i]/j]+= freq[arr[i]/j]*(n-1-i);
                    freq[arr[i]/j]++;
                }
            }
        }
    }
    ll ans= 0;
    for(int i= 100000; i>= 1; i--) {
        ll t= dp[i];
        for(int j= i*2; j<= 100000; j+= i) {
            t-= dp[j];
        }
        dp[i]= t;
        ans+= t*i;
    }
    cout<<ans<<endl;
}

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    
    while(t--){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}