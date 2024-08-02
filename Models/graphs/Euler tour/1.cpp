
// question: u r given a tree with n nodes and n-1 edges. node consists a character
// for each query 2 options are there:
// 1. change the character of node x to y
// 2. find whether can u make a palicdrome string by taking the characters of nodes in the subtree of node x

#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
#define pii pair<int, int>
typedef long long ll;
#define vi vector<ll>
#define fill(v) for(auto& i: v) cin>>i;
#define has(c, x) {return c.find(x)!=c.end();}
#define pr(v) for(auto i: v) cout<<i<<" "; cout<<endl;
#define pr1(v, i) for(auto j: v) cout<<j[i]<<" "; cout<<endl; 
#define del(s, x) if(s.find(x)!=s.end()) s.erase(s.find(x)) 
#define show(x) cout<<#x<<": "<<x<<" ";
#define rev(v) reverse(v.begin(), v.end())
#define endl() cout << endl
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 200005

vector<int> adj[MAXN];
vector<int> euler;

int tin[MAXN], tout[MAXN];

char c[MAXN];

int timer = 0;

void dfs(int u, int p){
    tin[u] = timer++;
    euler.push_back(u);
    for(int v: adj[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    tout[u] = timer++;
    euler.push_back(u);
}

int t[4*MAXN];
int A[4*MAXN];

void build(int node, int start, int end){
    if(start == end){
        t[node] = A[start];
    }
    else{
        int mid = (start + end) / 2;
        build(node*2, start, mid);
        build(node*2+1, mid+1, end);
        t[node] = t[node*2] ^ t[node*2+1];
    }
}

void update(int node, int start, int end, int idx, char val){
    if(start == end){
        t[node] = (1 << (val-'a'));
    }
    else{
        int mid = (start + end) >> 1;
        if(start <= idx && idx <= mid){
            update(node*2, start, mid, idx, val);
        }
        else{
            update(node*2+1, mid+1, end, idx, val);
        }
        t[node] = t[node*2] ^ t[node*2+1];
    }
}

int query(int node, int start, int end, int l, int r){
    if(r < start || end < l){
        return 0;
    }
    if(l <= start && end <= r){
        return t[node];
    }
    int mid = (start + end) >> 1;
    int p1 = query(node*2, start, mid, l, r);
    int p2 = query(node*2+1, mid+1, end, l, r);
    return p1 ^ p2;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    for(int i=0; i<n; i++){
        A[tin[i]] = (1 << (c[i]-'a'));
        A[tout[i]] = 0;
    }

    ll q;
    cin >> q;

    build(1, 0, 2*n-1);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            char y;
            cin >> x >> y;
            x--;
            c[x] = y;
            update(1, 0, 2*n-1, tin[x], y);

        }
        else{
            int x;
            cin >> x;
            x--;
            int ans = query(1, 0, 2*n-1, tin[x], tout[x]);
            int cnt = count_ones(ans);

            if(cnt <= 1){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }

}