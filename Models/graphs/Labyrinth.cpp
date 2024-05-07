#include <bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
#define pii pair<ll, ll>
typedef long long ll;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define endl() cout << endl
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"

// https://codeforces.com/problemset/problem/1666/L

vector<ll> adj[200005];
bool vis[200005];
ll parent[200005];
ll path[200005];

ll s, curr_path=1, t, second_path=-1;


bool dfs1(ll u){
    
    vis[u] = true;
    path[u] = curr_path;
    for(auto v: adj[u]){
        if(!vis[v]){
            parent[v] = u;
            if(dfs1(v)){
                return true;
            }
        }
        else if( v!= s && path[v]!= curr_path ){
            second_path = parent[v];
            parent[v] = u;
            t = v;
            return true;
        }
        if(u == s){
            curr_path++;
        }
    }
    return false;
}


void solve() {

    ll n, m;
    cin >> n >> m >> s;
    for(int i=0; i<m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    bool found = dfs1(s);

    if(!found){
        cout<<"Impossible\n";
        return;
    }

    cout<<"Possible\n";
    vector<ll> path1, path2;

    ll t1 = t;

    while(t1 != s){
        path1.pb(t1);
        t1 = parent[t1];
    }
    path1.pb(s);
    reverse(all(path1));

    path2.pb(t);
    t1 = second_path;
    while(t1 != s){
        path2.pb(t1);
        t1 = parent[t1];
    }
    path2.pb(s);
    reverse(all(path2));

    cout<<path1.size()<<endl;
    for(auto x: path1){
        cout<<x<<" ";
    }
    endl();

    cout<<path2.size()<<endl;
    for(auto x: path2){
        cout<<x<<" ";
    }
    endl();

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}