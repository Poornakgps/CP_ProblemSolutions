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
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define endl() cout<<endl
#define Yes() cout<<"YES\n"
#define No() cout<<"NO\n"
#define readtwo(x,y) ll x,y; cin >> x >> y
#define readl(x) ll x;cin >> x
#define readstring(s) string s;cin >> s
#define readarray(a, n) ll a[n];for (int i = 0; i < n; i++)cin >> a[i]
#define readvector(a, n) vector<ll> a(n);for (ll i = 0; i < n; i++)cin >> a[i]
#define readgraph(g, m) vector<ll> g[m];for (ll i = 0; i < m; i++){ll x, y;cin >> x >> y;g[x].pb(y);g[y].pb(x);}
#define readgraphw(g, m) vector<pair<ll,ll>> g[m];for (ll i = 0; i < m; i++){ll x, y, w;cin >> x >> y >> w;g[x].pb({y,w});g[y].pb({x,w});}
#define readgraphw2(g, m) vector<pair<ll,ll>> g[m];for (ll i = 0; i < m; i++){ll x, y, w;cin >> x >> y >> w;g[x].pb({y,w});}
#define readgraph2(g, m) vector<ll> g[m];for (ll i = 0; i < m; i++){ll x, y;cin >> x >> y;g[x].pb(y);}

// greater<int>(decreasing order) or less<int> (increasing order)
typedef tree< pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;

// templates
template <typename T> void out(T& message) { cout << message<<" "; }
 
template <typename T> void in(T& val) { cin>>val; }

void debug_int(int i){ cout<<i<<" "; }

void debug_str(string s){ cout<<s<<" "; }


/*******************************NUMBER THEORY****************************************/
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

void primeFactors(ll n) { 
    map<ll,ll> mp;
    while (n % 2 == 0) { 
        mp[2]++;
        n = n/2; 
    } 
    for (ll i = 3; i <= sqrt(n); i = i + 2) { 
        while (n % i == 0) { 
            mp[i]++;
            n = n/i; 
        } 
    } 
    if (n > 2) 
        mp[n]++;
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
int mex(vector<ll>& numberArray) {
    set<ll> sett;
    for(int i = 0; i < numberArray.size(); i++) 
        sett.insert(numberArray[i]);
    for(int i = 0; i < 1000001; i++)
        if(!sett.count(i)) return i;
    return -1;
}

/*******************************NUMBER THEORY****************************************/

/*******************************COMBINATORICS****************************************/
 
ll fact(ll n){
    if(n<=1)
        return 1;
    return ((n%mod_10)*(fact(n-1)%mod_10))%mod_10;
}

ll inv(ll a){ return binpow(a,mod_10-2,mod_10); }
 
ll ncr(ll n, ll r){
    if(r==0){
        return 1;
    }
    if(n<r){
        return 0;
    }
    ll ans = 1;
    ans = (ans*fact(n))%mod_10;
    ans = (ans*inv(fact(r)))%mod_10;
    ans = (ans*inv(fact(n - r)))%mod_10;
    return ans%mod_10;
} 
/*******************************COMBINATORICS****************************************/

void add_m(ll &a, ll b, ll m) {
    a += b;
    if (a >= m)
        a -= m;
}

ll sum_m(ll a, ll b, ll m) {
    a += b;
    if (a >= m)
        a -= m;
    if (a < 0)
        a += m;
    return a;
}

ll mul_m(ll a, ll b, ll m) {
    return (a * 1LL * b) % m;
}

/*******************************STRINGS****************************************/

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
/*******************************STRINGS****************************************/

/*******************************BITMANIPULATION****************************************/

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int last_one(int n){
    return log2(n & -n);
}

int first_one(int n){
    return log2(n);
}
/*******************************GRAPH****************************************/
class Graph{
 
    public:
        ll n,ans=1,fx[200001], siz[200001];
        vector<vector<ll>> comp;
        vector<vector<ll>> adj;
        vector<ll> cycle_lengths;
        vector<ll> vis, side;
        vector<ll> color;
        int timer;
        map<pii, int> is_bridge;
        vector<int> tin, low;

        Graph(ll n){
            this->n=n;
            adj.resize(n + 1);
            comp.resize(n + 1);
            vis.resize(n + 1);
            vis.assign(n + 1,0);
            side.resize(n + 1,-1);
            color.resize(n + 1,0);
            is_bridge.clear();
            tin.assign(n + 1,0);
            low.assign(n + 1,0);
            for(int i=1; i<=n; i++){
                fx[i]=i;            // dsu
                siz[i]=1;
                comp[i].pb(i);
            }
            timer = 0;
            find_bridges();

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
        bool is_bipartite(ll n) {

            bool is_bipartite = true;
            queue<int> q;
            for (int st = 0; st < n; ++st) {
                if (side[st] == -1) {
                    q.push(st);
                    side[st] = 0;
                    while (!q.empty()) {
                        int v = q.front();
                        q.pop();
                        for (int u : adj[v]) {
                            if (side[u] == -1) {
                                side[u] = side[v] ^ 1;
                                q.push(u);
                            } else {
                                is_bipartite &= side[u] != side[v];
                            }
                        }
                    }
                }
            }
            return is_bipartite;
        }
        void find_bridges() {  // O(n+m)
            vis.assign(n, false);
            tin.assign(n, -1);
            low.assign(n, -1);
            for (int i = 0; i < n; ++i) {
                if (!vis[i])
                    dfs_for_bridge(i);
            }
        }

        void find_bridges_online() {
            vector<int> par, dsu_2ecc, dsu_cc, dsu_cc_size;
            int bridges;
            int lca_iteration;
            vector<int> last_visit;

            // Initialization
            auto init = [&](int n) {
                par.resize(n);
                dsu_2ecc.resize(n);
                dsu_cc.resize(n);
                dsu_cc_size.resize(n);
                lca_iteration = 0;
                last_visit.assign(n, 0);
                for (int i = 0; i < n; ++i) {
                    dsu_2ecc[i] = i;
                    dsu_cc[i] = i;
                    dsu_cc_size[i] = 1;
                    par[i] = -1;
                }
                bridges = 0;
            };

            // Find 2-edge-connected component
            auto find_2ecc = [&](int v) -> int {
                if (v == -1)
                    return -1;
                return dsu_2ecc[v] == v ? v : dsu_2ecc[v] = find_2ecc(dsu_2ecc[v]);
            };

            // Find connected component
            auto find_cc = [&](int v) -> int {
                v = find_2ecc(v);
                return dsu_cc[v] == v ? v : dsu_cc[v] = find_cc(dsu_cc[v]);
            };

            // Make root
            auto make_root = [&](int v) {
                int root = v;
                int child = -1;
                while (v != -1) {
                    int p = find_2ecc(par[v]);
                    par[v] = child;
                    dsu_cc[v] = root;
                    child = v;
                    v = p;
                }
                dsu_cc_size[root] = dsu_cc_size[child];
            };

            // Merge path
            auto merge_path = [&](int a, int b) {
                ++lca_iteration;
                vector<int> path_a, path_b;
                int lca = -1;
                while (lca == -1) {
                    if (a != -1) {
                        a = find_2ecc(a);
                        path_a.push_back(a);
                        if (last_visit[a] == lca_iteration) {
                            lca = a;
                            break;
                        }
                        last_visit[a] = lca_iteration;
                        a = par[a];
                    }
                    if (b != -1) {
                        b = find_2ecc(b);
                        path_b.push_back(b);
                        if (last_visit[b] == lca_iteration) {
                            lca = b;
                            break;
                        }
                        last_visit[b] = lca_iteration;
                        b = par[b];
                    }
                }

                for (int v : path_a) {
                    dsu_2ecc[v] = lca;
                    if (v == lca)
                        break;
                    --bridges;
                }
                for (int v : path_b) {
                    dsu_2ecc[v] = lca;
                    if (v == lca)
                        break;
                    --bridges;
                }
            };

            // Add edge
            auto add_edge = [&](int a, int b) {
                a = find_2ecc(a);
                b = find_2ecc(b);
                if (a == b)
                    return;

                int ca = find_cc(a);
                int cb = find_cc(b);

                if (ca != cb) {
                    ++bridges;
                    if (dsu_cc_size[ca] > dsu_cc_size[cb]) {
                        std::swap(a, b);
                        std::swap(ca, cb);
                    }
                    make_root(a);
                    par[a] = dsu_cc[a] = b;
                    dsu_cc_size[cb] += dsu_cc_size[a];
                } else {
                    merge_path(a, b);
                }
            };

            // Test example
            init(5);  // Initialize with 5 nodes

            add_edge(0, 1);
            add_edge(1, 2);
            add_edge(1, 3);
            add_edge(3, 4);

            cout << "Number of bridges: " << bridges << endl;
        }
 
        void find_cycle_lengths(){
            for(int i=1; i<=n; i++){
                if(vis[i])
                    continue;      
                ll length=0;
                dfs_cycle_length(i,length);
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

        void find_cycle_directed_graph(){
            for(int i=1; i<=n; i++){
                if(color[i]==0){
                    if(dfs(i, -1, color)){
                        cout<<"Cycle found\n";
                        return;
                    }
                }
            }
            cout<<"No cycle found\n";
        }
 
    private:
        void dfs_cycle_length(ll node, ll &length){
            if(vis[node]) return;
            vis[node]=1;
            length++;     
            for(auto it: adj[node]){
                dfs(it, length);
            }
        }
        bool dfs(int v, int p, vector<ll> &color){
            color[v] = 1; // GREY
            bool ans=false;
            for(int w : adj[v]){
                if(color[w] == 1){
                    return true;
                // you found a cycle, it's easy to recover it now.
                }
                if(color[w] == 0) ans = dfs(w, v, color);
                if(ans) return true;
            }
            color[v] = 2; // BLACK
            return ans;
        }
        void dfs_for_bridge(int v, int p = -1) {
            vis[v] = true;
            tin[v] = low[v] = timer++;
            bool parent_skipped = false;
            for (int to : adj[v]) {
                if (to == p && !parent_skipped) {
                    parent_skipped = true;
                    continue;
                }
                if (vis[to]) {
                    low[v] = min(low[v], tin[to]);
                } else {
                    dfs(to, v);
                    low[v] = min(low[v], low[to]);
                    if (low[to] > tin[v])
                        is_bridge[{v, to}] = 1, is_bridge[{to, v}] = 1;
                }
            }
        } 
};

/*******************************GRAPH****************************************/

/******************************* STL ****************************************/

void vector__(){

    // reverse iteration
    vector<int> v = {34, 23, 43, 67, 444, 42, 53};
    for(auto it = v.rbegin(); it!=v.rend(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // back
    cout<<v.back()<<endl;

    // clear
    v.clear();

    // data
    vector<ll> v(10);

    ll *p = v.data();

    ll k = 1;
    for(int i=0;i<10;i++){
        v[i] = k;
        k++;
    }

    for(int i=0;i<10;i++){

        for(int j=0; j<10-i; j++){
            
            cout<<p[j]<<" ";
        }
        endl();
        p++;
    }

    // erase
    // erase the 6th element
    v.erase (v.begin()+5);

    // erase the first 3 elements:
    v.erase (v.begin(),v.begin()+3);
}

void multiset__(){
    // remove all elements up to element
    // with value 30 in gquiz2
    cout << "\ngquiz2 after removal \n"
            "of elements less than 30 : \n";
    gquiz2.erase(gquiz2.begin(), gquiz2.find(30));
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << *itr << " ";
    }

        // remove all elements with value 50 in gquiz2
    
    gquiz2.erase(50);

   // it will remove only one value of
    // 10 from multiset
    a.erase(a.find(10));
 
    // it will give output 2
    cout << a.count(10) << endl;
}

void strings__(){
      string str = "geeksforgeeks a computer science";
  char c = 'g';
 
  // Find first occurrence of 'g'
  size_t found = str.find(c);
  if (found != string::npos)
    cout << "First occurrence is " << 
             found << endl;
   
  // Find next occurrence of 'g'
  found = str.find(c, found + 1);
  if (found != string::npos)
    cout << "Next occurrence is " << 
             found << endl;

  string str = "geeksforgeeks a computer science";
   
  // Only search first 5 characters 
  // of "geeks.practice"
  size_t found = str.find("geeks.practice", 
                          0, 5);
  if (found != string::npos)
    cout << found << endl;

    char src[] = "geeksforgeeks"; 
 
    // Here destination is not large 
    // enough to store the src. so the 
    // behaviour of strcpy is unspecified. 
    // program may crashed, but its 
    // printing geeksforgeeks 
    char dest[2]; 
     
    // copying src into dest. 
    strcpy(dest, src); 
    cout << "Copied string: " << dest << endl; 


    // Using positions 
    cout << "Using positions:"
         << "\n"; 
    // Replaces 7 characters from 0th index by s2 
    s1.replace(0, 7, s2); 
    cout << s1 << endl; 
  
    // Replaces 3 characters from 0th index with "Hello" 
    s4.replace(0, 3, "Hello "); 
    cout << s4 << endl; 
  
    // Replaces 5 characters from 6th index of s4 with 
    // 5 characters from 0th of s3 
    s4.replace(6, 5, s3, 0, 5); 
    cout << s4 << endl; 
  
    // Replaces 5 characters from 6th index of s4 with 
    // 6 characters from string "to all" 
    s4.replace(6, 5, "to all", 6); 
    cout << s4 << endl; 
  
    // Replaces 1 character from 12th  index of s4 with 
    // 3 copies of '!' 
    s4.replace(12, 1, 3, '!'); 
    cout << s4 << endl; 
  
    // Using iterators 
    cout << "\nUsing iterators:"
         << "\n"; 
    // Replaces whole s2 string with s3 
    s2.replace(s2.begin(), s2.end(), s3); 
    cout << s2 << "\n"; 
  
    // Replaces 13 characters from begin of s1 with string 
    // "Example" 
    s1.replace(s1.begin(), s1.begin() + 13, "Example"); 
    cout << s1 << "\n"; 
  
    // Replace last 7 characters of s4 with first 12 
    // characters of the string "geeks from- here" 
    s4.replace(s4.end() - 7, s4.end(), "geeks from- here", 
               12); 
    cout << s4 << "\n"; 
  
    // Replaces last character with complete s2 string from 
    // s2.begin() till s2.end() 
    s4.replace(s4.end() - 1, s4.end(), s2.begin(), 
               s2.end()); 
    cout << s4 << "\n"; 
  
    // Replaces portion of string s4 starting from 5 
    // characters from s4.begin() to 15 characters from 
    // s4.begin() with 2 occurrences of ',' 
    s4.replace(s4.begin() + 5, s4.begin() + 15, 2, ','); 

   // Declaring integer
    int i_val = 20;
 
    // Declaring float
    float f_val = 30.50;
 
    // Conversion of int into string using
    // to_string()
    string stri = to_string(i_val);
 
    // Conversion of float into string using
    // to_string()
    string strf = to_string(f_val);

    // type of explicit type casting
  int myint1 = stoi(str1);
}
/******************************* STL ****************************************/