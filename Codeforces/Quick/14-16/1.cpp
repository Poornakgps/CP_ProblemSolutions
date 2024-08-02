// https://codeforces.com/problemset/problem/1733/D1

// Read Question Properly

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



void solve() {

    ll n, x, y;
    cin >> n >> x >> y;

    string a, b;
    cin >> a >> b;

    ll cnt=0;
    rep(i, 0, n, 1){
        if(a[i]!=b[i]){
            a[i] = '1';
            cnt++;
        }
        else{
            a[i] = '0';
        }
    }

    if(cnt%2){
        cout<<-1<<endl;
        return;
    }

    if(cnt == 0){
        cout<<0<<endl;
        return;
    }
    else if(cnt == 2){
        ll distance = 0;
        bool flag = 0;
        rep(i, 0, n, 1){
            if(a[i] == '1'){
                flag=!flag;
                continue;
            }

            if(flag){
                distance++;
            }
        }
        if(distance == 0){
            cout<<min(x, 2*y)<<endl;
            return;
        }
        ll ans = min((distance+1)*x, y);
        cout<<ans<<endl;
    }
    else{
        ll ans = (cnt/2)*y;
        cout<<ans<<endl;
        
    }
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