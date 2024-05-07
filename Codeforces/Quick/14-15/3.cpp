#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/1728/C

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



void solve() {

    ll n;
    cin >> n;
    
    priority_queue<ll> pqa, pqb;

    rep(i, 0, n, 1) {
        ll k;
        cin >> k;
        pqa.push(k);
    }

    rep(i, 0, n, 1) {
        ll k;
        cin >> k;
        pqb.push(k);
    }

    ll ans=0;

    while(!pqb.empty()){
        ll x=pqa.top();
        ll y=pqb.top();

        if(x==y){
            pqa.pop();
            pqb.pop();
            continue;
        }
        ans++;
        if(x>y){
            pqa.push(to_string(x).size());
            pqa.pop();
        }
        else{
            pqb.push(to_string(y).size());
            pqb.pop();
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}