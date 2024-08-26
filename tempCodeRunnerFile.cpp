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

void solve() {

    ll n;
    cin >> n;

    vector<pair<ll,ll>> edges;

    ll q = 15*n;

    vector<bool> vis(n+1, false);
    ll l = 1, r = 2;
    while(q--){

        cout<<"? "<<l<<" "<<r<<endl;
        cout.flush();

        ll x;
        cin>>x;
        cout.flush();

        if(x == l){
            edges.push_back({l, r});
            vis[l] = true, vis[r] = true;

            l = r;
            r = 1;
            while(r<=n && vis[r]){
                r++;
            }
            if(r>n){
                break;
            }
            continue;
        }

        if(vis[x] == true){
            l = x;
        }
        else{
            r = x;
        }

    }
    cout<<"! ";
    for(auto it: edges){
        cout<<it.ff<<" "<<it.ss<<" ";
    }
    endl();

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