#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005
#define ll long long
#define int long long
/***************************************C-H-A-O-S**************************************/

struct node {
    int num;
    int ind;
};

int n;
node t[4*MAXN];

node combine(node l, node r) {
    node res;
    res.num = l.num + r.num;
    return res;
}

node make_node(int val, int id) {
    node res;
    res.num = val;
    res.ind = id;
    return res;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_node(1, tl);
    } else{
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v] = make_node(0, tr);
        return;
    } 
    int tm = (tl + tr) / 2;
    if(t[v].num>=pos){

        if(t[2*v].num>=pos){
            update(v*2, tl, tm, pos);
        }
        else{
            update(2*v+1, min(tm+1, tr), tr, pos-t[2*v].num);
        }
    }
    t[v] = combine(t[v*2], t[v*2+1]);
}

node query(int v, int tl, int tr, int pos) {
    if (tl == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    if(t[v].num>=pos){

        if(t[2*v].num>=pos){
            return query(v*2, tl, tm, pos);
        }
        else{
            return query(2*v+1, min(tm+1, tr), tr, pos-t[2*v].num);
        }
    }
}

void solve() {

    int q;
    cin>>n;
    q=n;
    
    int arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];

    build(arr, 1, 0, n-1);

    while(q--){
        ll a;
        cin>>a;
        node nd = query(1, 0, n-1, a);
        cout<<arr[nd.ind]<<" ";
        update(1, 0, n-1, a);
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