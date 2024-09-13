#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005
#define ll long long
#define int long long
/***************************************C-H-A-O-S**************************************/

struct node {
    int mn;
};

int n;
node t[4*MAXN];

node combine(node l, node r) {
    node res;
    res.mn = min(l.mn, r.mn);
    return res;
}

node make_node(int val) {
    node res;
    res.mn = val;
    return res;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_node(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_node(new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

node query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return make_node(1e9);
    if (l == tl && r == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve() {

  int q;
  cin>>n>>q;
  
  int arr[n];

  for(int i=0; i<n; i++) cin>>arr[i];

  build(arr, 1, 0, n-1);

  while(q--){
    ll a, b, c;
    // a=2;
    cin>>a>>b>>c;
    if(a == 1){
      update(1, 0, n-1, b-1, c);
    }
    else{
      cout<<query(1, 0, n-1, b-1, c-1).mn<<endl;
    }
  }

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}