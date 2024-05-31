#include <bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
#define pii pair<ll, ll>
typedef long long ll;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define endl() cout << endl
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"

/***************************************C-H-A-O-S**************************************/
// https://codeforces.com/contest/505/problem/C

template <typename T>
void Read (T &x)
{
	T res = 0, f = 1;
	char ch = getchar ();
 
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar ();
	}
 
	while (ch >= '0' && ch <= '9')
	{
		res = res * 10 + ch - '0';
		ch = getchar ();
	}
	x = res * f;
}
 
template <typename T>
void Write (T x)
{
	if (x < 0) putchar ('-'), x = -x;
	if (x > 9) Write (x / 10);
	putchar ('0' + x % 10);
}

ll a[70001], dp[70001][500];

void solve() {

    ll n, d;
    Read(n), Read(d);
    rep(i, 0, n, 1){
        ll t;
        Read(t);
        a[t]++;
    }
    for(int i = 30000; i>=0; i--){
        for(int j=1; j<=491; j++){
            ll k = j+d-245;
            if(k==1){
                dp[i][j] =  max(dp[i+k][j], dp[i+k][j+1])+ a[i+k];
            }
            if(k>1){
                dp[i][j] =  max(dp[i+k][j], dp[i+k][j-1]);
                dp[i][j] = max(dp[i][j], dp[i+k][j+1])+ a[i+k];

            }
        }
    }
    Write(dp[0][245]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}