#include<bits/stdc++.h>
#define N 400005
#define int long long
using namespace std;

int q;
int parent[N][20];
int depth[N];
int path_wt[N][20]; // To store weights of the paths
int cnt; // To keep track of number of nodes

void update(int node, int p, int wt) {
    parent[node][0] = p;
    depth[node] = depth[p] + 1;
    path_wt[node][0] = wt;

    for (int bit = 1; bit < 20; bit++) {
        if (parent[node][bit - 1] != 0) {
            parent[node][bit] = parent[parent[node][bit - 1]][bit - 1];
            path_wt[node][bit] = path_wt[node][bit - 1] + path_wt[parent[node][bit - 1]][bit - 1];
        } else {
            parent[node][bit] = 0;
            path_wt[node][bit] = 0;
        }
    }
}

int lca_wt(int u, int max_wt) {
    int original_u = u;
    int last_weight = path_wt[u][0];  // Track the weight of the current node

    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != 0 && path_wt[parent[u][i]][0] >= last_weight && path_wt[u][i] <= max_wt) {
            max_wt -= path_wt[u][i];
            last_weight = path_wt[parent[u][i]][0]; // Update the last weight
            u = parent[u][i];
        }
    }

    return depth[original_u] - depth[u];
}

void solve() {
    cin >> q;
    int last = 0;
    memset(path_wt, 0, sizeof(path_wt));
    memset(depth, 0, sizeof(depth));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 20; j++) {
            parent[i][j] = 0;
        }
    }

    cnt = 2;
    while (q--) {
        int t, r, x;
        cin >> t >> r >> x;
        r ^= last;
        x ^= last;
        if (t == 1) {
            update(cnt, r, x);
            cnt++;
        } else {
            last = lca_wt(r, x);
            cout << last << endl;
        }
    }
}

signed main() {
    parent[1][0] = 0;
    int t = 1;
    while (t--) {
        solve();
    }
}
