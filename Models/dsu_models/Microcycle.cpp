#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second


int n, m;
const int N = 2e5 + 69;
int root[N];
vector <int> adj[N];
bool vis[N];
vector <int> path;

int find(int x){
    if (x == root[x]) return x;
    return root[x] = find(root[x]);
}

bool unite(int x, int y){
    x = find(x); y = find(y);
    if (x == y) return false;
    root[x] = y;
    return true;
}

void dfs(int u, int v){
    vis[u] = true;
    path.push_back(u);
    
    if (u == v){
        cout << path.size() << "\n";
        for (auto x : path){
            cout << x << " ";
        }
        cout << "\n";
    }
    
    for (int ne : adj[u]){
        if (!vis[ne]){
            dfs(ne, v);
        }
    }
    
    path.pop_back();
}

void Solve() 
{
    cin >> n >> m;
    
    vector <pair<int, pair<int, int>>> vec;
    for (int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        
        vec.push_back({w, {u, v}});
    }
    
    for (int i = 1; i <= n; i++){
        root[i] = i;
        vis[i] = false;
        adj[i].clear();
    }
    
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    
    int u = -1, v = -1;
    int ans = -1;
    
    for (auto x : vec){
        if (!unite(x.s.f, x.s.s)){
            ans = x.f;
            u = x.s.f;
            v = x.s.s;
        }
    }
    
    cout << ans << " ";
    for (int i = 1; i <= n; i++){
        root[i] = i;
    }
    // cout << u << " " << v << "\n";
    
    for (auto x : vec){
        unite(x.s.f, x.s.s);
        adj[x.s.s].push_back(x.s.f);
        adj[x.s.f].push_back(x.s.s);
        if (find(u) == find(v)){
            path.clear();
            dfs(u, v);
            break;
        }
    }
}

int32_t main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}