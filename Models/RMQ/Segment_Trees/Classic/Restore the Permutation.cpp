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
#define fill(v) for(auto& i: v) cin>>i;
#define has(c, x) {return c.find(x)!=c.end();}
#define pr(v) for(auto i: v) cout<<i<<" "; cout<<endl;
#define pr1(v, i) for(auto j: v) cout<<j[i]<<" "; cout<<endl; 
#define del(s, x) if(s.find(x)!=s.end()) s.erase(s.find(x)) 
#define show(x) cout<<#x<<": "<<x<<" ";
#define rev(v) reverse(v.begin(), v.end())
#define endl() cout << endl
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"

/***************************************C-H-A-O-S**************************************/
const int MAXN = 200005;
int n, tree[4 * MAXN];

void build(vector<ll> &a, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
    }
}

int get_first(int v, int tl, int tr, int l, int r, int x) {
    if (tl > r || tr < l) return -1;


    if (tree[v] <= x) return -1;

    if (tl == tr) return tree[v];

    int tm = (tl + tr) / 2; 

    int left = get_first(2 * v, tl, tm, l, r, x);

    if (left != -1) return left;

    return get_first(2 * v + 1, tm + 1, tr, l, r, x);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = -1;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);   
    }
}


void solve() {
    cin >> n;
    ll m = n / 2;
    vector<ll> v(m);
    map<ll, ll> mp;
    bool flag=0;
    for (int i = 0; i < m; i++) {
        cin >> v[i];
        if(mp[v[i]]){
            flag = 1;
        }
        mp[v[i]] = i + 1;

    }
    if(flag){
        cout<<-1<<endl;
        return;
    }

    vector<ll> rv(m);
    for (int i = 0; i < m; i++) {
        rv[i] = v[m - i - 1];
    }
    vector<ll> not_in_v;
    for (int i = 1; i <= n; i++) {
        if (mp.find(i) == mp.end()) {
            not_in_v.pb(i);
        }
    }
    build(rv, 1, 0, m - 1);
    ll per[n + 1];


    for (int i = m - 1; i >= 0; i--) {
        ll req = not_in_v[i];
        ll val = get_first(1, 0, m - 1, 0, m - 1, req);

        if (val == -1) {
            cout << -1 << endl;
            return;
        }
        per[2 * mp[val]] = val;
        per[2 * mp[val] - 1] = req;
        update(1, 0, m - 1, m-(mp[val]), -1);
    }
    for (int i = 1; i <= n; i++) {
        cout << per[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num_test_cases;
    cin >> num_test_cases;
    while (num_test_cases--) {
        solve();
    }
    return 0;
}