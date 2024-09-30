#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 300005;
const int MOD = 1e9 + 7;

// https://codeforces.com/contest/396/problem/C

int n, q; 
vector<int> g[MAXN];
int h[MAXN];
int s[MAXN], f[MAXN]; // start and finish time in Euler tour
int t = 0;
int hkx[4 * MAXN], sk[4 * MAXN];

void dfs(int v, int p, int height) {
    h[v] = height;
    s[v] = t++;
    for (int u : g[v]) {
        if (u != p) {
            dfs(u, v, height + 1);
        }
    }
    f[v] = t;
}

void update(int x, int k, int v, int id = 1, int l = 0, int r = n) {
    if (s[v] >= r || l >= f[v]) return;
    if (s[v] <= l && r <= f[v]) {
        hkx[id] = (hkx[id] + x) % MOD;
        int a = (1LL * h[v] * k) % MOD;
        hkx[id] = (hkx[id] + a) % MOD;
        sk[id] = (sk[id] + k) % MOD;
        return;
    }
    int mid = (l + r) / 2;
    update(x, k, v, 2 * id, l, mid);
    update(x, k, v, 2 * id + 1, mid, r);
}

int ask(int v, int id = 1, int l = 0, int r = n) {
    int a = (1LL * h[v] * sk[id]) % MOD;
    int ans = (hkx[id] + MOD - a) % MOD;
    if (r - l < 2) return ans;
    int mid = (l + r) / 2;
    if (s[v] < mid)
        return (ans + ask(v, 2 * id, l, mid)) % MOD;
    return (ans + ask(v, 2 * id + 1, mid, r)) % MOD;
}

void solve() {
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        int u;
        cin >> u;
        g[i].push_back(u);
        g[u].push_back(i);
    }
    cin>>q;

    dfs(1, -1, 0);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int v, x, k;
            cin >> v >> x >> k;
            update(x, k, v);
        } else {
            int v;
            cin >> v;
            cout << ask(v) << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}
