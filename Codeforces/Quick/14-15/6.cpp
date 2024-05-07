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

// https://codeforces.com/problemset/problem/1425/A
// power of 4 multiple

void solve() {

    ll n;
    cin >> n;

    ll a = 0, v = n, b=0, turn = 1;

    while(n){
        if(turn%2){
            if(n<5){
                a+=(max(1ll, (n-1)));
                b++;
                break;
            }
            else if(n%2 || n%4==0){
                a++;
                n--;
            }
            else{
                a+=n/2;
                n=n/2;
            }
        }
        else{
            if(n<5){
                b+=(max(1ll, (n-1)));
                a++;
                break;
            }
            else if(n%2 || n%4==0){
                b++;
                n--;
            }
            else{
                b+=n/2;
                n=n/2;
            }
        }
        turn++;
    }
    cout<<a<<endl;
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