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
#define N_LMT 200200

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
    
    ll n,m, q;
    cin>>n>>m>>q;

    vector<int> a(n), b(m);

    map<int, int> conv;
    ll cnt = 1;
    for(auto &i: a){
        cin>>i;
        conv[i] = cnt;
        cnt++;
    }

    for(auto &i: b){  
        cin>>i;
        i = conv[i];
    }
    ll hash1 = n*(n+1)/2, hash2=0;
    
    map<int, int> first_occ;
    cnt = 1;
    for(int i=0; i<m; i++){
        if(first_occ[b[i]]){
            continue;
        }
        first_occ[b[i]] = i+1;
        hash2 = b[i]*(cnt);
        cnt++;
    }
    cout<<cnt<<endl;
    hash1 = cnt*(cnt-1)*(2*cnt-1)/6;
    bool possible = true;
    if(hash1!=hash2){
        possible = false;
    }



    if(possible){
        cout<<"YA\n";
    }
    else{
        cout<<"TIDAK\n";
    }
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