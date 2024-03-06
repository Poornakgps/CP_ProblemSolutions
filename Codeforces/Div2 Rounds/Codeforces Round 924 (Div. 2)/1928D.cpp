#include"../../../template.h"

ll strength(ll k, ll mp[], ll n, ll b, ll x){
    ll ans=0;
    for(int i=0; i<n; i++){
        ll val = mp[i], cnt=1;
        if(val<=k){
            ans+= (val*(val-1)/2)*(cnt)*(b);
            continue;
        }
        ll rem = val%k;
        ll div = val/k;
        ll x= rem*(div+1);
        ll y= (k-rem)*div;
        ll curr=0;
        curr += (x*y ); // 1 from different sets
        curr += (div+1)*(div+1)*(rem)*(rem-1)/2; // 1 from same set1
        curr += (div)*(div)*(k-rem)*(k-rem-1)/2; // 1 from same set2
        ans+= curr*cnt*b;
    }
    return ans- x*(k-1);
}
 
void solve(){
 
    ll n,b,x;
    cin>>n>>b>>x;
 
    ll arr[n];   
    ll mx=0;
    rep(i, 0, n, 1) cin>>arr[i], mx=max(mx, arr[i]);
 
    ll l=1, r=mx;
    ll ans=0;
    ll val1= strength(l, arr, n, b, x), val2= strength(r, arr, n, b, x);
 
    ans= max(val1, val2);
    while(l<=r){
        ll mid = (l+r)/2;
        ll s1= strength(mid, arr, n, b, x), s2= strength(mid+1, arr, n, b, x);
        if(s1<=s2){
            ans= max(ans, s2);
            l=mid+1;
        }
        else{
            ans= max(ans, s1);
            r=mid-1;
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
