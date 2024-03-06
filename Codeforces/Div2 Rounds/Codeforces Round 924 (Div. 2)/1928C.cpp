#include"../../../template.h"

void get_factors(vector<ll> &v, ll n){
    for(int i=1; i*i<=n; i++ ){
        if(n%i==0){
            v.pb(i);
            if(i!=n/i)
                v.pb(n/i);
        }   
    }
}
void solve(){
 
    ll n,x;
    cin>>n>>x;
    if((n+x)%2){
        cout<<0<<endl;
        return;
    }
    vector<ll> fac;
    ll ans=0;
    map<ll,ll> mp;
    get_factors(fac, n-x);
    sort(fac.begin(), fac.end());
 
    for(auto it: fac){
        if(it<x){
            continue;
        }
        if(2*it-2>0 && (n-x)%(2*it-2)==0 ){
            ans++;
            mp[it]=1;
        }
        if(it%2){
            continue;
        }
        ll l= it/2 - 1, r= it/2 + 1;
        if(l>=x && !mp[l]&& 2*l-2>0 && (n-x)%(2*l-2)==0 ){
            ans++;
            mp[l]=1;
        }
        if(r>=x && 2*r-2>0 && !mp[r] && (n-x)%(2*r-2)==0 ){
            ans++;
            mp[r]=1;
        }
    }
 
    vector<ll> fac1;
    get_factors(fac1, n+x-2);
    sort(fac1.begin(), fac1.end());
 
    for(auto it: fac1){
        if(it<x){
            continue;
        }
        if(2*it-2>0 && !mp[it] && (n+x-2)%(2*it-2)==0 ){
            ans++;
            mp[it]=1;
        }
        if(it%2){
            continue;
        }
        ll l= it/2 - 1, r= it/2 + 1;
        if(2*l-2>0 &&  l>=x && !mp[l] && (n+x-2)%(2*l-2)==0 ){
            ans++;
            mp[l]=1;
        }
        if(2*r-2>0 &&r>=x && !mp[r] && (n+x-2)%(2*r-2)==0 ){
            ans++;
            mp[r]=1;
        }
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