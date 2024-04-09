#include<bits/stdc++.h>
 
using namespace std;
 
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for(ll i = a; i < (b); i+=c)
#define all(x) begin(x), end(x)
#define pii pair<ll, ll>
typedef long long ll;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define endl() cout<<endl
#define Yes() cout<<"YES\n"
#define No() cout<<"NO\n"


struct Hash{

    ll mod1 = 1e9+7, mod2 = 1e9+9;
    ll p1 = 31, p2 = 37;
    vector<ll> pow1, pow2;

    Hash(ll n){
        pow1.resize(n);
        pow2.resize(n);

        pow1[0] = 1;
        pow2[0] = 1;
        for(int i = 1; i < n; i++){
            pow1[i] = (pow1[i-1] * p1) % mod1;
            pow2[i] = (pow2[i-1] * p2) % mod2;
        }
    }
    pair<ll, ll> get_hash(ll i){
        return {pow1[i], pow2[i]};
    }

}hs(1000005);

void add(pii &a, pii b){
    a.ff = (a.ff + b.ff) % hs.mod1;
    a.ss = (a.ss + b.ss) % hs.mod2;
}

void solve(){

    ll n, m;
    cin >> n >> m;

    vector<pii> clique_score(n), adj_score(n);
    for(int i=0; i<n; i++){
        clique_score[i] = hs.get_hash(i);
    }

    for(int i=0; i<m; i++){
        ll u, v;
        cin >> u >> v;
        u--, v--;

        add(clique_score[u], hs.get_hash(v));
        add(clique_score[v], hs.get_hash(u));
        add(adj_score[u], hs.get_hash(v));
        add(adj_score[v], hs.get_hash(u));
    }

    map<pii, ll> mp;
    ll ans=0;
    for(auto it: adj_score){
        ans+= mp[it];
        mp[it]++;
    }
    mp.clear();
    for(auto it: clique_score){
        ans+= mp[it];
        mp[it]++;
    }  
    cout<< ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}