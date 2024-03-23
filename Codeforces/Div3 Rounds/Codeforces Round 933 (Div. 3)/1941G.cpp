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

// bipartitie graph concept 

void solve(){ 

    ll n, m;
    cin >> n >> m;
    vector<pii> adj[n+1];
    map<ll,ll> colors;
    ll id = n+1;
    rep(i, 0, m, 1){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        if(!colors[w]){
            colors[w] = id++;
        }
    }

    ll source , destination;
    cin >> source >> destination;

    vector<set<ll>> new_adj(id + 1);

    for(int i=1; i<=n; i++){
        for(auto x: adj[i]){
            new_adj[i].insert(colors[x.ss]);
            new_adj[colors[x.ss]].insert(i);
            new_adj[x.ff].insert(colors[x.ss]);
            new_adj[colors[x.ss]].insert(x.ff);
        }
    }
    vector<ll> vis(id + 1);
    vector<ll> dist(id + 1, -1);

    queue<ll> q;
    q.push(source);
    dist[source] = 0;
    vis[source] = 1;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(auto x: new_adj[u]){
            if(!vis[x]){
                vis[x] = 1;
                dist[x] = dist[u] + 1;
                q.push(x);
            }
        }
    }
    cout << (dist[destination]/2) << endl;
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