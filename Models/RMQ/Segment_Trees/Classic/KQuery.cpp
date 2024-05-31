#include <bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
#define pii pair<ll, ll>
typedef long long ll;

/***************************************C-H-A-O-S**************************************/

ll s[4*30000];
ll n;


void build(int ind = 1, int l = 0, int r = n){

    if(r-l<2){
        s[ind] = 1;
        return;
    }
    ll mid= (l+r)/2;
    build(2*ind, l,mid);
    build(2*ind+1, mid, r);
    s[ind]= s[2*ind]+s[2*ind+1];

}

void update(int p, int ind = 1, int l = 0, int r = n){

    if(r-l<2){
        s[ind] = 0;
        return;
    }
    ll mid= (l+r)/2;
    if(p<mid){
        update(p,2*ind, l, mid);
    }
    else{
        update(p, 2*ind+1, mid, r);
    }
    s[ind]= s[2*ind]+s[2*ind+1];

}

int sum(int x, int y, int id = 1,int l = 0,int r = n){// [x, y)
	if(x >= r or l >= y)	
        return 0;

	if(x <= l && r <= y)
		return s[id];

	int mid = (l + r)/2;

	return sum(x, y, id * 2, l, mid) + sum(x, y, id*2+1, mid, r) ;
}


void solve() {

    cin>>n;

    vector<pii> a(n);
    rep(i, 0, n, 1) {
        cin>>a[i].ff;
        a[i].ss = i;
    }
    sort(all(a));

    vector<ll> p(n);
    rep(i, 0, n, 1) {
        p[a[i].ss] = i;
    }
    
    ll q;
    cin>>q;
    ll i[q], j[q];
    vector<pii> k(q);
    for(int query = 0; query < q; query++){
        
        cin>>i[query]>>j[query]>>k[query].ff;
        // i[query]--, j[query]--;// 0-based indexing
        k[query].ss = query;
    }
    sort(all(k));

    build();
    int po = 0;
    vector<ll> ans(q, 0);
    for(int y = 0;y < q;++ y){
        int x = k[y].ss;
        while(po < n && a[p[po]].ff <= k[y].ff)
            update(p[po++]);
        ans[x] = sum(i[x], j[x]+1) -1; //  interval [i[x], j[x]] in 0-based indexing
    }

    for(int x = 0;x < q;++ x)
        cout<<ans[x]<<endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}