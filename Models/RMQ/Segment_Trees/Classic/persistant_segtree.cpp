#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int L[MAXN * 40], R[MAXN * 40], s[MAXN * 40];
int NEXT_FREE_INDEX = 1;
int root[MAXN + 1];

// Build function to initialize the segment tree
void build(int id = 0, int l = 0, int r = MAXN) {
    s[id] = 0;
    if (r - l < 2) return;
    int mid = (l + r) / 2;
    L[id] = NEXT_FREE_INDEX++;
    R[id] = NEXT_FREE_INDEX++;
    build(L[id], l, mid);
    build(R[id], mid, r);
    s[id] = s[L[id]] + s[R[id]];
}

// Update function to create new versions of segment tree
int upd(int p, int id, int l = 0, int r = MAXN) {
    int ID = NEXT_FREE_INDEX++;  // new version of segment tree
    s[ID] = s[id] + 1;
    if (r - l < 2) return ID;
    int mid = (l + r) / 2;
    L[ID] = L[id];
    R[ID] = R[id];
    if (p < mid)
        L[ID] = upd(p, L[ID], l, mid);
    else
        R[ID] = upd(p, R[ID], mid, r);
    return ID;
}

// Query function to find the k-th element in the range
int ask(int old_id, int new_id, int k, int l = 0, int r = MAXN) {
    if (r - l < 2) return l;
    int mid = (l + r) / 2;
    int left_sum = s[L[new_id]] - s[L[old_id]];
    if (left_sum >= k)
        return ask(L[old_id], L[new_id], k, l, mid);
    else
        return ask(R[old_id], R[new_id], k - left_sum, mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), sorted_a(n), p(n), q(n);
    
    // Reading input
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted_a[i] = a[i];
    }

    // Sorting elements to calculate the permutation
    sort(sorted_a.begin(), sorted_a.end());
    for (int i = 0; i < n; i++)
        p[i] = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin();
    for (int i = 0; i < n; i++)
        q[p[i]] = i;

    // Building the initial segment tree
    build();
    root[0] = 0;

    // Updating the segment tree for each i
    for (int i = 0; i < n; i++) {
        root[i + 1] = upd(q[i], root[i]);
    }

    // Handling queries
    for (int i = 0; i < m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        int idx = ask(root[l - 1], root[r], k);
        cout << sorted_a[idx] << '\n';
    }

    return 0;
}
