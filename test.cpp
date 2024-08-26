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
#define  MAXN 300005
#define N_LMT 100001

/***************************************C-H-A-O-S**************************************/


pair<ll,ll> hsh[MAXN];
void pre(){
    hsh[0] = {1,1};
    for(int i=1; i<67000; i++){
        hsh[i].ff = (hsh[i-1].ff*31)%mod_10;
        hsh[i].ss = (hsh[i-1].ss*29)%mod_9;
    }
}

vector<ll> adj[MAXN];
bool vis[MAXN];
vector< pair<ll,ll> >  store(MAXN);

pair<ll,ll> dfs_get_hsh(ll node, ll parent = 1, ll depth = 1){

    pair<ll,ll> node_hsh = {(hsh[depth].ff)%mod_10 , (hsh[depth].ss)%mod_9};
    pair<ll,ll> child_hsh = {hsh[depth+1].ff,hsh[depth+1].ss};
    for(auto child: adj[node]){
        if(child == parent) continue;
        child_hsh = {(dfs_get_hsh(child, node, depth+1).ff + child_hsh.ff)%mod_10, (dfs_get_hsh(child, node, depth+1).ss + child_hsh.ss)%mod_9};
    }
    // cout<<node<<" "<<child_hsh.ff<<" "<<child_hsh.ss<<endl;
    node_hsh = {(node*(child_hsh.ff))%mod_10, (node*(child_hsh.ss))%mod_9};

    store[node] = {parent, depth};
    // cout<<parent<<" "<<depth<<" "<<node<<" "<<node_hsh.ff<<" "<<node_hsh.ss<<endl;
    return node_hsh;   // return hsh of subtree rooted at node
}

void solve() {

    ll n, q;
    cin >> n >> q;
    vi a(n+1);
    adj[1].clear();
   store[1] = {0,0};
    for(int i=2; i<=n; i++){
        cin >> a[i];
        adj[i].clear();
        adj[a[i]].pb(i);
        adj[i].pb(a[i]);
        store[i] = {0, 0};
    }
    pair<ll,ll> req_hsh = dfs_get_hsh(1);

    vi permutation(n+1);
    for(int i=1; i<=n; i++){
        cin >> permutation[i];
    }
    pair<ll,ll> curr_hsh = {0,0};

    for(int i=1; i<=n; i++){
        // cout<<store[permutation[i]].ff<<" "<<store[permutation[i]].ss<<" "<<permutation[i]<<" "<<<<endl;
        if(permutation[i] == 1) continue;
        curr_hsh = {(curr_hsh.ff + (hsh[store[permutation[i]].ss].ff*store[permutation[i]].ff)%mod_10 )%mod_10, (curr_hsh.ss + (hsh[store[permutation[i]].ss].ss*store[permutation[i]].ff)%mod_9 )%mod_9 };
    } 
    cout<<curr_hsh.ff<<" "<<curr_hsh.ss<<endl;
    cout<<req_hsh.ff<<" "<<req_hsh.ss<<endl;
    cout<< (curr_hsh == req_hsh ? "YES" : "NO") << endl;
    
    
    // while(q--){
    //     ll x, y;
    //     cin >> x >> y;

    //     swap(adj[x], adj[y]);

        
    //     curr_hsh = {curr_hsh.ff - p[x]*hshes[x].ff, curr_hsh.ss - p[x]*hshes[x].ss};
    //     curr_hsh = {curr_hsh.ff + p[y]*hshes[x].ff, curr_hsh.ss + p[y]*hshes[x].ss};
    // }
    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    cin >> t;
    pre();
    while (t--){
        solve();
    }
    return 0;
}