#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;

void solve() {

    ll n, q;
    cin >> n >> q;

    vector<ll> a(n+1), pre(n+1, 0);
    for(int i=1; i<=n; i++){
        cin>>a[i];

        pre[i]+= (pre[i-1] + abs(a[i]- a[i-(i>1)]));
    }

    while(q--){
        ll l, r, k;
        cin>>l>>r>>k;
        ll d = pre[r]-pre[l];

        ll t =  (d - abs(a[r]-a[l]))/2;
        ll cover = d-k;
        ll t2 = max(0ll, ((d - k) + 1)/2);

        ll ans = min(t, t2);

        cover -= ans*2;

        if(cover>0){
            ans+= cover;
        }
        
        cout<<ans<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}