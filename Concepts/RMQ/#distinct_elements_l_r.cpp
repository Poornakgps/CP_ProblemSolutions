#include<bits/stdc++.h>

using namespace std;
#define F first
#define S second
using ii = pair<int, int>
using vii = vector<pair<int, int>>;

int n;
int arr[100100];
int t[4*100100];
void build(int id, int l, int r){
    t[id] = 0;
    int mid = (l+1)>>1;

    build((id<<1), l, mid);
    build(id<<1|1, mid+1, r);
}
void update(int id, int l, int r, int pos, int val){

    if(pos<l || pos>r || l>r){
        return;
    }
    if(l==r){
        t[id] = val;
        return;
    }
    int mid = (l+1)>>1;
    update(id<<1, l, mid, pos, val);
    update(id<<1|1, mid+1, r, pos, val);
    t[id] = t[id<<1] + t[id<<1|1];
}
int query(int id, int l, int r, int lq, int rq){
    if(lq>r || l>rq) return 0;

    if(lq<=l && r<=rq){
        return t[id];
    }
    int mid = (l+r)>>1;
    return query(id<<1, l, mid, lq, rq) + query((id<<1)|1, mid+1, r, lq, rq);
}
void solve(){
    cin>>n;
    vii p;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        p.push_back({arr[i], i});
    }
    sort(p.begin(), p.end());
    vector<pair<ii, ii>> queries;

    for(int i=0; i<q; i++){
        int l, r, k;
        cin>>l>>r>>k;
        queries.push_back({k, i}, {l, r});
    }
    sort(queries.begin(), queries.end());
    int ans[q];
    build(1, 0, n-1);
    int pos = 0;
    for(auto v: queries){
        while(pos<p.size()&& p[pos].F<=v.F.F){
            update(1, 0, n-1, p[pos].S, 1);
            pos++;
        }
        ans[v.F.S] = query(1, 0, n-1, v.S.F, v.S.S);
    }
    for(int i=0; i<q; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main(){

    ios_base::sync_with_stdio(0), cin.tie(0), cour.tie(0);

    solve();
}