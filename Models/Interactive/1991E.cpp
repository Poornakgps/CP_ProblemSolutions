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
#define N_LMT 100001

/***************************************C-H-A-O-S**************************************/

vector<ll> adj[10005];
vector<int> side(10005, -1);
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
void solve() {

    ll n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        adj[i].clear();
        side[i] = -1;
    }
    for(int i=0; i<m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    } 

    if(!is_bipartite(n)){
        cout<<"Alice\n";
        cout.flush();
        for(int i=1; i<=n; i++){
            ll a, b;
            cout<<1<<" "<<2<<endl;
            cout.flush();
            cin>>a>>b;
        }
    }
    else{
        deque<ll> ev, od;
        for(int i=1; i<=n; i++){
            if(side[i]==0) ev.pb(i);
            else od.pb(i);
        }
        cout<<"Bob\n";
        cout.flush();
        while(n--){
            ll a, b;
            cin>>a>>b;
            cout.flush();

            if((a==1 || b==1) && ev.size()){
                cout<<ev.front()<<" "<<1<<endl;
                ev.pop_front();
            }
            else if((a==2 || b==2) && od.size()){
                cout<<od.front()<<" "<<2<<endl;
                od.pop_front();
            }
            else{
                if(ev.size()){
                    cout<<ev.front()<<" "<< 3 <<endl;
                    ev.pop_front();
                }
                else{
                    cout<<od.front()<<" "<< 3 <<endl;
                    od.pop_front();
                }
                cout.flush();
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}