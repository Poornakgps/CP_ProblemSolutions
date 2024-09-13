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
void add_m(ll &a, ll b) {
    a += b;
}

ll mul_m(ll a, ll b, ll m) {
    return (a * 1LL * b) % m;
}

void solve() {

	int n;
	cin>>n;

	ll arr[n+2];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	stack<ll> st;

	vector<ll> l(n+1, -1), r(n+1, n);

	for(int i=0; i<n; i++){
		while(!st.empty() && arr[st.top()] <= arr[i]){
			st.pop();
		}
		if(!st.empty()){
			l[i] = st.top();
		}
		if(st.empty()){
			st.push(i);
			continue;
		}
		if(arr[st.top()]<=arr[i])
			st.push(i);
	}
	while(!st.empty()){
		st.pop();
	}
	for(int i=n-1; i>=0; i--){
		while(!st.empty() && arr[st.top()]<=arr[i]){
			st.pop();
		}

		if(!st.empty()){
			r[i] = st.top();
		}
		if(st.empty()){
			st.push(i);
			continue;
		}
		if(arr[st.top()]<=arr[i])
			st.push(i);
	}
	ll a[n+1]={};
	ll ans = 0;
	for(int i=0; i<n; i++){
		// cout<<l[i]<<" "<<r[i]<<" "<<arr[i]<<endl;
		if(l[i] !=-1 && r[i]!=n){
			ans += min(arr[l[i]], arr[r[i]]) - arr[i] + a[l[i]];
			a[i] = ans;
		}
	}
	cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    cin >> t;
    while (t--){
        solve();
    }
}