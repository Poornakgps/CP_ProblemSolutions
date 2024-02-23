#include<bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1931/F

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for(ll i = a; i < (b); i+=c)
#define all(x) begin(x), end(x)
typedef long long ll;
#define endl() cout<<endl
#define Yes() cout<<"YES\n"
#define No() cout<<"NO\n"
/************************** 1000000007 ****************************/

bool dfs(int v, int p, vector<ll> g[], vector<ll> &color){
    color[v] = 1; // GREY
    bool ans=false;
    for(int w : g[v]){
        if(color[w] == 1){
            return true;
        // you found a cycle, it's easy to recover it now.
        }
        if(color[w] == 0) ans = dfs(w, v, g, color);
        if(ans) return true;
    }
    color[v] = 2; // BLACK
    return ans;
}

void solve(){ 
    ll n, k;
    cin>>n>>k;
    vector<ll> v[n+1];
    map<pair<ll,ll> , ll> mp;
    for(int i=0; i<k; i++){
        ll x, y;
        for(int j=0; j<n; j++){
            cin>>x;
            if(j>1 && mp[{y,x}]==0){
                v[y].pb(x);
                mp[{y,x}]=1;
            }
            y=x;    
        }
    }
    vector<ll> color(n+1, 0);
    for(int i = 0; i < n; i++)
        if(color[i] == 0 && dfs(i,-1, v, color)){
            cout << "NO\n";
            return;
        }
    Yes();
    
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}