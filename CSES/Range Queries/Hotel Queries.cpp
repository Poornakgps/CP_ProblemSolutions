#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005
#define ll long long
#define int long long
/***************************************C-H-A-O-S**************************************/

struct node {
    int mx;
    int ind;
};

int n;
node t[4*MAXN];

node combine(node l, node r) {
    node res;
    if(l.mx>=r.mx){
        res.ind = l.ind;
    }
    else{
        res.ind = r.ind;
    }
    res.mx = max(l.mx, r.mx);
    return res;
}

node make_node(int val, int id) {
    node res;
    res.mx = val;
    res.ind = id;
    return res;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        // cout<<tl<<" "<<a[tl]<<endl;
        t[v] = make_node(a[tl], tl);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_node(new_val, tl);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

node query(int v, int tl, int tr, int val) {
    if (tl > tr || t[v].mx < val) {
        return make_node(-1, -1);
    }
    
    if(tl==tr){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if(t[v].mx>=val){
        if(t[2*v].mx>=val){
            return query(v*2, tl, max(tm, tl), val);
        }
        else{
            return query(v*2+1, min(tm+1, tr), tr, val);
        }
    }
}

void solve() {

    int q;
    cin>>n>>q;
    
    int arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];

    build(arr, 1, 0, n-1);

    while(q--){
        int k;
        cin>>k;

        node nd = query(1, 0, n-1, k);
        if(nd.mx==-1){
            cout<<0<<" ";
            continue;
        }
        cout<<nd.ind+1<<" ";
        update(1, 0, n-1, nd.ind, nd.mx-k);  
    }
    cout<<endl;

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