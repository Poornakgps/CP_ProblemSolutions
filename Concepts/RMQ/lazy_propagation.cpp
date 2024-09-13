#include<bits/stdc++.h>

using namespace std;
#define MAXN 100100

struct node{
    int sum, mx, lazy;
    node(){
        sum = 0;
        mx = 0;
        lazy = 0;
    }
};

node merge_n(node a, node b){
    node temp;
    temp.sum = a.sum + b.sum;
    temp.mx = max(a.mx, b.mx);
    return temp;
}

node t[4*MAXN];

void push(int id, int l, int r){
    if(t[id].lazy){
        t[id].sum = t[id].lazy*(r-l+1); 
        t[id].mx = t[id].lazy;
        if(l!=r){
            t[id<<1].lazy = t[id].lazy;
            t[id<<1|1].lazy = t[id].lazy;
        }
        t[id].lazy = 0;
    }
}

void update(int id, int l, int r, int lq, int rq, int v){
    push(id, l, r);
    if(rq<l || lq>r) return;

    if(lq<=l && r<=rq){
        t[id].lazy = v;
        push(id, l, r);
        return; 
    }
    int mid = (l+r)>>1;
    update(id<<1, l, mid, lq, rq, v);
    update((id<<1)|1, mid+1, r, lq, rq, v);
    t[id] = merge_n(t[id<<1] , t[(id<<1)|1]);
}

node query(int id, int l, int r, int lq, int rq){
    push(id, l, r);
    if(rq<l || lq>r) return node();
    if(lq<=l && r<=rq){
        return t[id];
    }
    int mid = (l+r)>>1;
    return merge_n(query(id<<1, l, mid, lq, rq), query((id<<1)|1, mid+1, r, lq, rq));
}

void solve(){
    update(1, 0, 9, 0, 5, 3);
    update(1, 0, 9, 6, 9, 4);
    node x = query(1, 0, 9, 3, 6);
    cout<<x.sum<<" "<<x.mx<<endl;
}

signed main(){
    solve();
}