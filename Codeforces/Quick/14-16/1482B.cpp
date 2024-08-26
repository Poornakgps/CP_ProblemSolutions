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
    vi v(n);
    fill(v);
    bool f = false;
    for(int i=0; i<n; i++){
        if(v[i]!=v[0]){
            f = true;
            break;
        }
    }
    if(!f){
        cout << 0 << endl;
        return;
    }
    ll l = -1;
    for(int i=1; i<n; i++){
        if(v[i]>v[i-1]){
            if(l!=-1 && l!=v[i]-v[i-1]){
                cout << -1 << endl;
                return;
            }
            l = v[i]-v[i-1];
        }
    }
    ll r = -1;
    for(int i=1; i<n; i++){
        if(v[i]<=v[i-1]){
            if(r!=-1 && r!=v[i-1]-v[i]){
                cout << -1 << endl;
                return;
            }
            r = v[i-1]-v[i];
        }
    }
    
    if(l==-1 || r==-1){
        cout << 0 << endl;
        return;
    }

    if(v[0]>r+l){
        cout << -1 << endl;
        return;
    }
    for(int i=1; i<n; i++){
        if((v[i-1]+ l)%(l+r)!=v[i]){
            cout << -1 << endl;
            return;
        }
    }

    cout << l+r << " " << l << endl;
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