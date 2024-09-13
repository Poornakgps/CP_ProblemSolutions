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

int dp[3005][3005];
string s, t;
int n, m;

int lcs(int i, int j){
    if(i==n || j==m){
        return 0;
    }
    // cout<<i<<" "<<j<<endl;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = 0;

    if(s[i]==t[j]){
        ans = 1 + lcs(i+1, j+1);
    }
    else{
        ans = max(lcs(i+1, j), lcs(i, j+1));
    }
    return dp[i][j] = ans;
}

vector<char> solution;

void generate(int i, int j) {
    // BaseCase
    if (i == n || j==m) return;

    // Transition
    if(s[i]==t[j]){
        solution.push_back(t[j]);
        generate(i+1, j+1);
    }
    else{
        int lft = dp[i+1][j];
        int rgt = dp[i][j+1];
        if(lft>rgt){
            generate(i+1, j);
        }
        else{
            generate(i, j+1);
        }
    }
}
void solve() {

    cin>>s>>t;
    n = s.size(), m = t.size();
    memset(dp, -1, sizeof(dp));
    int lcs_length = lcs(0, 0);

    // cout<<lcs_length<<endl;

    generate(0, 0);

    for(auto it: solution){
        cout<<it;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    while (t--){
        solve();
    }
}