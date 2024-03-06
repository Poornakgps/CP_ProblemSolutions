#include"../../../template.h"


void solve(){
 
    ll n;
    cin>>n;
    vector<ll> v;
    map<ll,ll> mp;
    for(int i=0; i<n; i++){
        ll x;
        cin>>x;
        if(mp[x]){
            continue;
        }
        mp[x]=1;
        v.pb(x);
    }
 
    ll k= v.size();
    ll ans=1;
    // cout<<k<<endl;
    // endl();
    sort(v.begin(), v.end());
    for(int i=0; i<k; i++){
        auto it= lower_bound(v.begin(), v.end(), v[i]+n)-v.begin();
        // cout<<it<<" ";
        // cout<<v[i]+n<<"\n";
        ans= max(ans, 1ll*(it)-i);
    }
    cout<<ans<<endl;
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