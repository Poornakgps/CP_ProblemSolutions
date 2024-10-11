#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
typedef long long ll;
#define pii pair<ll, ll>
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
#define testcase_(i, val) cout<<"Case #"<<i<< ": "<< val<<endl;
#define mod_10 1000000009
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 300005
#define N_LMT 200200

void debug(vi v){

    for(auto it: v){
        cerr<<it<<" ";
    }
    cerr<<endl;
}

ll gcd(ll a, ll b){ if(b==0) return a; else return gcd(b,a%b); }

int mex(vector<ll>& numberArray) {  // munda mex
    set<ll> sett;
    for(int i = 0; i < numberArray.size(); i++) 
        sett.insert(numberArray[i]);
    for(int i = 0; i < 1000001; i++)
        if(!sett.count(i)) return i;
    return -1;
}

ll binpow(ll a, ll b, ll m ) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res%m;
}

// https://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html

vector<ll> adj[N_LMT];
vector<ll> depth(N_LMT, 0), symmetrical(N_LMT, 0), hsh(N_LMT, 0);

ll dfs_depth(int node, int par = 0){
    depth[node] = 1;
    ll mx_depth = 0;

    for(auto child: adj[node]){
        if(child == par) continue;

        mx_depth = max(mx_depth, dfs_depth(child, node));
    }
    depth[node] = mx_depth + depth[node];
    return depth[node];
}

ll dfs_hash(int node, int par = 0){
    hsh[node] = 1;
    map<ll, ll> cnt; // freq of each hash
    map<ll, ll> mp;
    vector<ll> od; // odd freq hash if exists
    for(auto child: adj[node]){
        if(child == par) continue;

        ll tmp = dfs_hash(child, node);

        hsh[node]  = ((hsh[node])*(depth[node] + tmp)%mod_10)%mod_10;
        cnt[tmp]++;
        mp[tmp] = child;
    }
    hsh[node] = (hsh[node] * depth[node])%mod_10;

    for(auto it: cnt){
        if(it.ss & 1) od.pb(mp[it.ff]);
    }

    if(od.size()>1) symmetrical[node] = 0;

    else if(od.size()==0) symmetrical[node] = 1;

    else{
        symmetrical[node] = symmetrical[od[0]];
    }
    return hsh[node];
}

void solve() {
    
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        adj[i].clear();
        depth[i] = 0;
        symmetrical[i] = 0;
    }

    for(int i=0; i<n-1; i++){
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll ans = dfs_depth(1);
    ans = dfs_hash(1);

    if(symmetrical[1]){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    int i=1;
    while (t--) {
        solve();
        // cout<<solve()<<endl;
        // testcase_(i, solve());
        i++;
    }

    return 0;
}