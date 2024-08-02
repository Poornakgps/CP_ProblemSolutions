#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int N = 2e5 + 5;
const int INF = 1e9;
const long long INF_LL = 1e18;

struct Edge {
    int s, e, w, id;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int n, m;
long long res = 0, ans = INF_LL;
vector<Edge> edges;
vector<int> h(N, 0), present(N, 0);
vector<vector<pair<int, int>>> adj(N), dp(N, vector<pair<int, int>>(21));
vector<vector<int>> up(N, vector<int>(21, -1));

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    vector<int> v = {a.first, a.second, b.first, b.second};
    sort(v.rbegin(), v.rend());
    return {v[0], v[1]};
}

void dfs(int u, int par, int d) {
    h[u] = h[par] + 1;
    up[u][0] = par;
    dp[u][0] = {d, -1};
    for (auto v : adj[u]) {
        if (v.first != par) {
            dfs(v.first, u, v.second);
        }
    }
}

pair<int, int> lca(int u, int v) {
    pair<int, int> ans = {-2, -3};
    if (h[u] < h[v]) swap(u, v);
    for (int i = 20; i >= 0; --i) {
        if (h[u] - h[v] >= (1 << i)) {
            ans = combine(ans, dp[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) return ans;
    for (int i = 20; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            ans = combine(ans, combine(dp[u][i], dp[v][i]));
            u = up[u][i];
            v = up[v][i];
        }
    }
    ans = combine(ans, combine(dp[u][0], dp[v][0]));
    return ans;
}

int main() {
    cin >> n >> m;
    edges.resize(m);
    UnionFind uf(n + 1);  // Use n + 1 to handle 1-indexed nodes

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].s >> edges[i].e >> edges[i].w;
        edges[i].id = i;
    }

    sort(edges.begin(), edges.end());

    for (const auto& e : edges) {
        if (uf.unite(e.s, e.e)) {
            adj[e.s].emplace_back(e.e, e.w);
            adj[e.e].emplace_back(e.s, e.w);
            present[e.id] = 1;
            res += e.w;
        }
    }

    dfs(1, 0, 0);

    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (up[j][i - 1] != -1) {
                int v = up[j][i - 1];
                up[j][i] = up[v][i - 1];
                dp[j][i] = combine(dp[j][i - 1], dp[v][i - 1]);
            }
        }
    }

    for (const auto& e : edges) {
        if (!present[e.id]) {
            auto rem = lca(e.s, e.e);
            if (rem.first != e.w) {
                ans = min(ans, res + e.w - rem.first);
            } else if (rem.second != -1) {
                ans = min(ans, res + e.w - rem.second);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
