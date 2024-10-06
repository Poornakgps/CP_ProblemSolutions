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
#define  MAXN 300005
#define N_LMT 100001
#define janu main
 
/***************************************C-H-A-O-S**************************************/
int mex(vector<ll>& numberArray) {  // munda mex
    set<ll> sett;
    for(int i = 0; i < numberArray.size(); i++) 
        sett.insert(numberArray[i]);
    for(int i = 0; i < 1000001; i++)
        if(!sett.count(i)) return i;
    return -1;
}
ll gcd(ll a, ll b){ if(b==0) return a; else return gcd(b,a%b); }
 
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
void add_m(ll &a, ll b) {
    a += b;
}
 
ll mul_m(ll a, ll b, ll m) {
    return (a * 1LL * b) % m;
}

vector<ll> get_divisors(ll n){

    vector<ll> div;
    int p = n;
    // div.pb(1);
    for(int i=2; i*i<= p; i++){

        if(n%i == 0){
            while(n%i==0){
                div.pb(i);
                n = n / i;
            }
        }
    }
    if(n!=1){
        div.pb(n);
    }
    // div.pb(p);
    sort(all(div));
    return div;
}
 
void solve() {

    ll p;
    cin>>p;


    vector<ll> div = get_divisors(p);

    if(p==1){
        cout<<41<<" ";
        for(int i=0; i<41; i++){
            cout<<1<<" ";
        }
        return;
    }

    if(div.size() == 0){
        if(p == 41){
            cout<<1<<" "<<41;
        }
        else{
            cout<<-1;
        }
        return;
    }
    ll sum = 0;
    for(auto it: div){
        sum+= it;
    }
    if(sum>41){
        cout<<-1;
        return;
    }

    for(int i=0; i<41-sum; i++){
        div.pb(1);
    }
    if(div.size()>100){
        cout<<-1;
        return;
    }
    cout<<div.size()<<" ";
    sort(all(div));
    for(auto it: div){
        cout<<it<<" ";
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
        cout<<fixed<<setprecision(12)<<"Case #"<<i<< ": ";
        solve();
        cout<<endl;
        i++;
    }
 
    return 0;
}