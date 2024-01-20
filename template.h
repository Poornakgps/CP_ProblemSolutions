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
        ll n,ans=1,fx[100001], siz[100001];
        map<ll, vector<ll>> comp;
        vector<vector<ll>> adj;
        vector<ll> cycle_lengths;
        vector<ll> vis;
        Graph(ll n){
            this->n=n;
            adj.resize(n + 1);
            vis.resize(n+1);
            vis.assign(n+1,0);
            for(int i=1; i<=n; i++){
                fx[i]=i;            // dsu
                siz[i]=1;
                comp[i].pb(i);
            }
        }
        void add_directed_edge(ll u, ll v){
 
            adj[u].push_back(v);
        }
 
        void print_adjlist(){
 
            for(auto it: adj){
                for(auto it1: it){
                    cout<<it1<<" ";
                }
                cout<<endl;
            }
        }
 
        void find_cycle_lengths(){
            for(int i=1; i<=n; i++){
                if(vis[i])
                    continue;      
                ll length=0;
                dfs(i,length);
            }
        }
 
        ll dsu(ll n){      //dsu
            
            if(fx[n]==n) return n;
 
            return dsu(fx[n]);
        }
 
        void dsu_update(ll x, ll y){
 
            if(siz[fx[x]]> siz[fx[y]]){    
                siz[fx[x]]+=siz[fx[y]];
                siz[fx[y]]=0;
                for(auto it: comp[fx[y]]){
                    fx[it]=fx[x];    
                    comp[fx[x]].pb(it);
                }
                comp.erase(y);
            }
            else{
                siz[fx[y]]+=siz[fx[x]];
                for(auto it: comp[fx[x]]){
                    fx[it]=fx[y];
                    comp[fx[y]].pb(it);
                }
                comp.erase(x);
            }
        }
 
    private:
        void dfs(ll node, ll &length){
            
            if(vis[node]) return;
            vis[node]=1;
            length++;     
            for(auto it: adj[node]){
                dfs(it, length);
            }
        }
};