#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int n, D, arr[100100];

map<ll, ll> compVal;

int t[400400];

void update(int id, int l, int r, int pos, int val){
    if(pos<l || pos>r) return;

    if(l==r){
        t[id] = max(t[id], val);
        return; 
    }
    int mid = (l+r)>>1;
    update(id<<1, l, mid, pos, val);
    update((id<<1)|1, mid+1, r, pos, val);
    t[id] = max(t[id<<1] , t[(id<<1)|1]);
}

int query(int id, int l, int r, int lq, int rq){
    if(lq>r || l>rq) return 0;

    if(lq<=l && r<=rq){
        return t[id];
    }
    int mid = (l+r)>>1;
    return max(query(id<<1, l, mid, lq, rq), query((id<<1)|1, mid+1, r, lq, rq));
}


void solve(){
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        compVal[arr[i]];
    }
    cin>>D;
    int cnt = 0;

    for(auto &v: compVal){
        v.second = cnt++;
    }
    int ans = 0;
    int dp[n];
    for(int i=0; i<n; i++){
        int lo = arr[i]-D;
        int hi = arr[i]+D;
        auto it = compVal.upper_bound(hi);
        it--; hi = it->second;

        it = compVal.lower_bound(lo);
        lo = it->second;

        dp[i] = query(1, 0, cnt-1, lo, hi) + 1;
        ans = max(ans, dp[i]);
        update(1, 0, cnt-1, compVal[arr[i]], dp[i]);
    }
    cout<<ans<<endl;

}
signed main(){
    solve();
}