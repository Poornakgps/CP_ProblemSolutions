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
// #define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 100005

/***************************************C-H-A-O-S**************************************/

// https://codeforces.com/contest/1986/problem/F

vector<ll> adj[MAXN];

bool visited[MAXN];
ll tin[MAXN], low[MAXN];
int timer;
map<pii, int> is_bridge;
vector<int> sub_graph_size(MAXN, 0);

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            sub_graph_size[v] += sub_graph_size[to];
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                is_bridge[{v, to}] = 1, is_bridge[{to, v}] = 1;
        }
    }
    sub_graph_size[v]+=1;
}

void solve(){
    
    ll n, m;
    cin >> n >> m;
    vector<pii> edges;
    for(int i=1; i<=n; i++){
        adj[i].clear();
        visited[i] = false;
        tin[i] = 0;
        low[i] = 0;
        sub_graph_size[i] = 0;
    }
    is_bridge.clear();


    for(int i=0; i<m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.pb({u, v});
    }

    timer = 0;
    dfs(1);


    ll ans = n*(n-1)/2;

    for(auto i: edges){
        ll u = i.ff, v = i.ss;
        if(is_bridge[{u, v}] == 1){
            ll sz1 = 0, sz2 = 0;
            if(sub_graph_size[u] > sub_graph_size[v]){
                sz1 = sub_graph_size[v];
                sz2 = n - sub_graph_size[v];
            } else {
                sz1 = n - sub_graph_size[u];
                sz2 = sub_graph_size[u];
            }
            ans = min(ans, sz1*(sz1-1)/2 + sz2*(sz2-1)/2);
        } 
    }
    cout<<ans<<endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}