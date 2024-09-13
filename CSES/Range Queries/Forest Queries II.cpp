#include <bits/stdc++.h>
using namespace std;

struct node {
    int sum;
};

int n, m;
node t[4000][4000];
vector<string> a(1002); 

node combine(node l, node r) {
    node res;
    res.sum = l.sum + r.sum;
    return res;
}

node make_node(int val = 0) {
    node res;
    res.sum = val;
    return res;
}

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = make_node(a[lx][ly] == '*');
        else
            t[vx][vy] = combine(t[vx * 2][vy], t[vx * 2 + 1][vy]);
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy * 2, ly, my);
        build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry);
        t[vx][vy] = combine(t[vx][vy * 2], t[vx][vy * 2 + 1]);
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx * 2, lx, mx);
        build_x(vx * 2 + 1, mx + 1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m - 1);
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = make_node(new_val);
        else
            t[vx][vy] = combine(t[vx * 2][vy], t[vx * 2 + 1][vy]);
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
        t[vx][vy] = combine(t[vx][vy * 2], t[vx][vy * 2 + 1]);
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx * 2, lx, mx, x, y, new_val);
        else
            update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 1, 0, m - 1, x, y, new_val);
}

node sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry)
        return make_node(0);
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return combine(sum_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy)),
                   sum_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
}

node sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return make_node(0);
    if (lx == tlx && trx == rx)
        return sum_y(vx, 1, 0, m - 1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return combine(sum_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry),
                   sum_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
}

void solve() {
    int q;
    cin >> n >> q;
    m = n; 

    for (int i = 0; i < n; i++) cin >> a[i];

    build_x(1, 0, n - 1);

    while (q--) {
        int type=2;
        cin>>type;
        if (type == 1) { 
            int x, y;
            cin >> x >> y;
            x--; y--; 
            int new_val = (a[x][y] == '*') ? 0 : 1;
            a[x][y] = (a[x][y] == '*') ? '.' : '*';
            update_x(1, 0, n - 1, x, y, new_val);
        } else if (type == 2) { 
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--; y1--; x2--; y2--; 
            cout << sum_x(1, 0, n - 1, x1, x2, y1, y2).sum << "\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
