#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
#define pii pair<int, int>
typedef long long ll;
#define vi vector<ll>
#define fill(v) for(auto& i: v) cin>>i;
#define has(c, x) {return c.find(x)!=c.end();}
#define pr(v) for(auto i: v) cout<<i<<" "; cout<<endl;
#define pr1(v, i) for(auto j: v) cout<<j[i]<<" "; cout<<endl; 
#define del(s, x) if(s.find(x)!=s.end()) s.erase(s.find(x)) 
#define show(x) cout<<#x<<": "<<x<<" ";
#define rev(v) reverse(v.begin(), v.end())
#define endl() cout << endl
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 200005

/***************************************C-H-A-O-S**************************************/

// Minimum cost to make array bitonic starting it can trail or end by any number of zeros but once a non zero 
// starts it should increase and decrease to 1 with defference 1

void solve(){
    
    ll n;
    cin>>n;
    vi v(n);
    fill(v);

    vector<pii> suff(n), pref(n);
    pref[0] = {1, v[0]-1};
    suff[n-1] = {1, v[n-1]-1};

    for(int i=1; i<n; i++){
        if(pref[i-1].ff+1<v[i]){
            pref[i] = {pref[i-1].ff+1, pref[i-1].ss+(v[i]-(pref[i-1].ff+1))};
        }
        else if(pref[i-1].ff+1>v[i]){
            ll val = pref[i-1].ff+1;
            ll cnt = (val*(val-1)/2)  -  (v[i]*(v[i] - 1)/2) ;// bring all prefix elements to number which trailes by 1
            pref[i] = {v[i], pref[i-1].ss + cnt};
        }
        else{
            pref[i] = {v[i], pref[i-1].ss};
        }
    }
    // for(int i=0; i<n; i++){
    //     cout<<pref[i].ff<<" "<<pref[i].ss<<endl;
    // }

    for(int i=n-2; i>=0; i--){
        if(suff[i+1].ff+1<v[i]){
            suff[i] = {suff[i+1].ff+1, suff[i+1].ss+ (v[i]-(suff[i+1].ff+1))};
        }
        else if(suff[i+1].ff+1>v[i]){
            ll val = suff[i+1].ff+1;
            ll cnt = (val*(val-1)/2)  -  (v[i]*(v[i]-1)/2) ;// bring all suffix elements to number which trailes by 1
            suff[i] = {v[i], suff[i+1].ss + cnt};
        }
        else{
            suff[i] = {v[i], suff[i+1].ss};
        }
    }
    // endl();
    // for(int i=0; i<n; i++){
    //     cout<<suff[i].ff<<" "<<suff[i].ss<<endl;
    // }

    ll ans = 1e9;
    for(int i=1; i<n-1; i++){
        ll cnt = 0;

        if(pref[i].ff<suff[i].ff){
            ll val = suff[i].ff;
            ll c = (val*(val-1)/2)  -  (pref[i].ff*(pref[i].ff-1)/2) ;
            cnt = pref[i].ss + suff[i].ss + c;
        }
        else if(pref[i].ff>suff[i].ff){
            ll val = pref[i].ff;
            ll c = (val*(val-1)/2)  -  (suff[i].ff*(suff[i].ff-1)/2) ;

            cnt = pref[i].ss + suff[i].ss + c;
        }
        else{
            cnt = pref[i].ss + suff[i].ss;
        }
        ans = min(ans, cnt);
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}