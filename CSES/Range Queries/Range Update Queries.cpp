#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005

#define int long long
/***************************************C-H-A-O-S**************************************/

struct node {
    int sum ;
};

int n;
node t[4*MAXN];

node combine(node l, node r) {
    node res;
    res.sum = l.sum + r.sum;
    return res;
}

node make_node(int val = 1e9) {
    node res;
    res.sum = val;
    return res;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_node(0);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int l, int r, int inc) {

    if(tl>=l && tr<=r){
        t[v].sum += inc;
        return;
    }
    if(tr<l || tl>r || tl>tr){
        return;
    }
    int tm = (tl+tr)/2;
    update(2*v, tl, tm, l, r, inc);
    update(2*v+1, tm+1, tr, l, r, inc);
}

node query(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v];
    }
    else{
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return make_node(t[v].sum + query(v*2, tl, tm, pos).sum);
        else
            return make_node(t[v].sum + query(v*2+1, tm+1, tr, pos).sum);
    }
}

void solve() {

  int q;
  cin>>n>>q;
  
  int arr[n];

  for(int i=0; i<n; i++) cin>>arr[i];

  build(arr, 1, 0, n-1);

  while(q--){
    int a;
    cin>>a;
    if(a == 1){
        int l, r, v;
        cin>>l>>r>>v;
        update(1, 0, n-1, l-1, r-1, v);
    }
    else{
        int p;
        cin>>p;
        node ans = query(1, 0, n-1, p-1);
        cout<<ans.sum + arr[p-1]<<endl;
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