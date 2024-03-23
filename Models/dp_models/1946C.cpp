#include<bits/stdc++.h>
// https://codeforces.com/contest/1946/problem/C

// DP + DFS
using namespace std;

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for(ll i = a; i < (b); i+=c)
#define all(x) begin(x), end(x)
#define pii pair<ll, ll>
typedef long long ll;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define endl() cout<<endl
#define Yes() cout<<"YES\n"
#define No() cout<<"NO\n"


vector<ll> adj[100005];

ll subtree_size[100005], number_of_components[100005];


void dfs(ll node, ll parent , ll x){
    subtree_size[node] = 1;
    number_of_components[node] = 0;

    for(auto child: adj[node]){

        if(child != parent){
            
            dfs(child, node, x);

            subtree_size[node] += subtree_size[child];
            number_of_components[node] += number_of_components[child];
        }
    }
    if(subtree_size[node]>=x){
        subtree_size[node] = 0;
        number_of_components[node]++;
    }
}

bool check(ll mid, ll k){

    dfs(1, -1, mid);

    if(number_of_components[1] >= k + 1){
        return true;
    }
    return false;

}

void solve(){ 

    ll n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        adj[i].clear();
    }
    rep(i, 0, n-1, 1){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll l=1, r = n;
    ll ans=0;
    while(l<=r){
        ll mid = (l+r+1)/2;

        if(check(mid, k)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans << endl;
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