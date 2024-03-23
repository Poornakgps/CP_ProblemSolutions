#include<bits/stdc++.h>

using namespace std;

// https://codeforces.com/contest/1934/problem/D2
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for(ll i = a; i < (b); i+=c)
#define all(x) begin(x), end(x)
#define pii pair<ll, ll>
typedef long long ll;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define count_ones(x) __builtin_popcount(x) 
#define endl() cout<<endl
#define Yes() cout<<"YES\n"
#define No() cout<<"NO\n"


/************************** 1000000007 ****************************/

void solve() 
{
    ll n; cin >> n;
    
    ll cnt = __builtin_popcountll(n);
    if (cnt % 2 == 1){
        cout << "second" << endl;
        while (1){
            ll x, y; cin >> x >> y;
            
            if (x == 0 && y == 0){
                return;
            }
            ll cntx=__builtin_popcountll(x);
            if (cntx % 2 == 0){
                n=x;
            } else {
                n=y;
            }
            
            ll a = 0;
            for(int i=63; i>=0; i--){
                if((1LL<<i)&n){
                    a=i;
                    break;
                }
            }
            cout << (n - (1LL << a)) << " " << (1LL << a) << endl;
        }
    } 
    else {
        cout << "first" << endl;
        while (1){
            ll a = 0;
            for(int i=63; i>=0; i--){
                if((1LL<<i)&n){
                    a=i;
                    break;
                }
            }
            cout << (n - (1LL << a)) << " " << (1LL << a) << endl;
            
            ll x, y; cin >> x >> y;
            
            if (x == 0 && y == 0){
                return;
            }
            ll cntx=__builtin_popcountll(x);
            if (cntx%2 == 0){
                n=x;
            } else {
                n=y;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
