#include <bits/stdc++.h>
using namespace std;

#define MAXN 200100

int n;
vector<int> t[4 * MAXN];
int arr[MAXN];

// Build the segment tree in O(n log n)
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {arr[tl]};
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v].resize(t[v * 2].size() + t[v * 2 + 1].size());
        merge(t[v * 2].begin(), t[v * 2].end(),
              t[v * 2 + 1].begin(), t[v * 2 + 1].end(),
              t[v].begin());
    }
}

// Update the segment tree in O(log^2 n)
void update(int v, int tl, int tr, int pos, int old_val, int new_val) {
    auto it = lower_bound(t[v].begin(), t[v].end(), old_val);
    if (it != t[v].end() && *it == old_val) {
        t[v].erase(it);
    }
    t[v].insert(upper_bound(t[v].begin(), t[v].end(), new_val), new_val);

    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, old_val, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, old_val, new_val);
    } else {
        arr[pos] = new_val;
    }
}

// Query the range [l, r] for the number of elements between [a, b]
int query(int v, int tl, int tr, int l, int r, int a, int b) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return upper_bound(t[v].begin(), t[v].end(), b) -
               lower_bound(t[v].begin(), t[v].end(), a);
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm), a, b) +
           query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, a, b);
}

void solve() {
    int q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> arr[i];

    build(1, 0, n - 1);

    while (q--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == '!') {
            a--;  // Convert to 0-based index
            update(1, 0, n - 1, a, arr[a], b);
        } else {
            cout << query(1, 0, n - 1, 0, n - 1, a, b) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
