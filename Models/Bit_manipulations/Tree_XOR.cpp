#include<bits/stdc++.h>
#include<chrono>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
 
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
 
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for(ll i = a; i < (b); i+=c)
#define all(x) begin(x), end(x)
#define size(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MOD 1000000007
#define MOD1 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define endl() cout<<endl
#define readtwo(x,y) ll x,y; cin >> x >> y
#define readl(x) ll x;cin >> x
#define readstring(s) string s;cin >> s
#define readarray(a, n) ll a[n];for (int i = 0; i < n; i++)cin >> a[i]
#define readvector(a, n) vector<ll> a(n);for (ll i = 0; i < n; i++)cin >> a[i]
// greater<int>(decreasing order) or less<int> (increasing order)
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;

// templates
template <typename T> void out(T& message) { cout << message<<" "; }
 
template <typename T> void in(T& val) { cin>>val; }

void debug_int(int i){ cout<<i<<" "; }

void debug_str(string s){ cout<<s<<" "; }

ll gcd(ll a, ll b){ if(b==0) return a; else return gcd(b,a%b); }  // gcd
 
ll lcm(ll a, ll b){ return (a*b)/(gcd(a,b)); }   // lcm

void get_factors(vector<ll> &v, ll n){
    for(int i=1; i*i<=n; i++ ){
        if(n%i==0){
            v.pb(i);
            if(i!=n/i)
                v.pb(n/i);
        }   
    }
}

bool is_prime(ll n){            
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
 
ll binpow(ll a, ll b, ll m = 1e18) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
ll fact(ll n){
    if(n<=1)
        return 1;
    return ((n%MOD1)*(fact(n-1)%MOD1))%MOD1;
}

ll inv(ll a){ return binpow(a,MOD-2,MOD); }
 
ll ncr(ll n, ll r){
    if(r==0){
        return 1;
    }
    if(n<r){
        return 0;
    }
    ll ans = 1;
    ans = (ans*fact(n))%MOD;
    ans = (ans*inv(fact(r)))%MOD;
    ans = (ans*inv(fact(n - r)))%MOD;
    return ans%MOD;
} 

// strings
vector<ll> z_function(string s) { 
    ll n = size(s);
    vector<ll> z(n);
    ll l = 0, r = 0;
    for(ll i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
 
    return z;
 
}
vector<ll> prefix_function(string s) {
    int n = (int)s.length();
    vector<ll> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

class Graph{
    public:
        ll n,ans=0, parent;
        vector<vector<ll>> adj;
        vector<ll> ans_arr, len, node_weight;
        Graph(ll n){
            this->n=n;
            adj.resize(n + 1);
            node_weight.resize(n+1);
            node_weight.assign(n+1,0);
            ans_arr.resize(n);
            ans_arr.assign(n,0);
            len.resize(n+1);
            len.assign(n+1,0);
        }
        void add_undirected_edge(ll u, ll v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        void print_adjlist(){
            for(auto it: adj){
                for(auto it1: it){
                    cout<<it1<<" ";
                }
                cout<<endl;
            }
        }
        void Algorithm_Tree_Xor(){
            for(auto it: adj[1]){  
                dfs(it, 1, 0, 0);
                len[1]+=len[it];
            }
            len[1]++;
            ans_arr[0]=ans;
            for(auto it: adj[1]){
                dfs2(it, 1);
            }
            // dfs for 1 as root vertex
        }
        void print_ans(){
            for(auto it: ans_arr){
                cout<<it<<" ";
            }
            endl();
        }
         void print_len(){
            for(auto it: len){
                cout<<it<<" ";
            }
            endl();
        }
    private:
        void dfs(ll node, ll parent, ll curr, ll k){
            ans+= k + (curr^node_weight[0]^node_weight[node-1]);
            k= ans;
            for(auto it: adj[node]){
                if(it!=parent)
                    dfs(it, node, curr^node_weight[node-1]^node_weight[0], k), len[node]+=len[it];;
            }
            len[node]++;
        }

        void dfs2(ll node, ll parent){
            ll k = (node_weight[parent-1]^node_weight[node-1]);
            //cout<<k<<" "<<node<<endl;
            ans_arr[node-1]= ans_arr[parent-1]+(len[parent] - len[node] - 1 )*k - (len[node]-1)*k;
            len[node]+= (len[parent]-len[node]);
            for(auto it: adj[node]){
                if(it != parent){
                    dfs2(it, node);
                }
            }
        }
};

void solve(){

    ll n;
    in(n);
    Graph g(n);
    rep(i,0,n,1){
        ll t;
        cin>>t;
        g.node_weight[i]=t;
    }
    
    ll ans=0;
    ll sz= n;
    for(int i=0; i<sz-1; i++){
        ll u,v;
        cin>>u>>v;
        g.add_undirected_edge(u,v);
    }
    // g.print_adjlist();
    g.Algorithm_Tree_Xor();
    // cout<<g.ans<<endl;
    g.print_ans();
}

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    
    while(t--){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}