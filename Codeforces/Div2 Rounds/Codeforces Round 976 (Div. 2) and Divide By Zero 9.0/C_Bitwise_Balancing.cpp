#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
typedef long long ll;
#define pii pair<ll, ll>
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
#define testcase_(i, val) cout<<"Case #"<<i<< ": "<< val<<endl;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 300005
#define N_LMT 100001

void debug(vi v){

    for(auto it: v){
        cerr<<it<<" ";
    }
    cerr<<endl;
}

ll gcd(ll a, ll b){ if(b==0) return a; else return gcd(b,a%b); }

int mex(vector<ll>& numberArray) {  // munda mex
    set<ll> sett;
    for(int i = 0; i < numberArray.size(); i++) 
        sett.insert(numberArray[i]);
    for(int i = 0; i < 1000001; i++)
        if(!sett.count(i)) return i;
    return -1;
}

ll binpow(ll a, ll b, ll m ) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res%m;
}

void solve() {

    ll b, c, d;
    cin>>b>>c>>d;
    ll a = 0;

    for(int i=0; i<=60; i++){

        ll val = pow(2, i);
        if( (val & c) && (val & d)){
            if(val&b){
                continue;
            }
            cout<<-1<<endl;
            return;
        }
        else if( (val&c) && !(val & d) ){    
            if(val&b){
                a+= (val);
            }
        }
        else if( !(val&c) && (val&d) ){
            a+= (val);
        }
        else{
            if(val&b){
                cout<<-1<<endl;
                return;
            } 
        }
    }
    cout<<a<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    int i=1;
    while (t--) {
        solve();
        // cout<<solve()<<endl;
        // testcase_(i, solve());
        i++;
    }

    return 0;
}