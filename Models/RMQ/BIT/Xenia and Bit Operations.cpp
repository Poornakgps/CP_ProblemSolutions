#include <bits/stdc++.h>

// https://codeforces.com/contest/339/problem/D

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

vector<ll> decomposition_tree[17]; // atmost 17 decompositions

void solve() {

    ll n, m;
    cin >> n >> m;
    ll arr[(1<<n)];
    for(int i=0; i<(1<<n); i++)
        cin >> arr[i];

    for(int i=0; i<=n; i++){

        for(int j=0; j<(1<<(n-i)); j++){
            if(i==0)
                decomposition_tree[i].pb(arr[j]);
            else{
                if(i%2)
                    decomposition_tree[i].pb(decomposition_tree[i-1][2*j] | decomposition_tree[i-1][2*j+1]);
                else
                    decomposition_tree[i].pb(decomposition_tree[i-1][2*j] ^ decomposition_tree[i-1][2*j+1]);
            }
        }
    }


    while(m--){
        ll p, b;
        cin >> p >> b;
        p--;
        decomposition_tree[0][p] = b;
        for(int i=1; i<=n; i++){
            p /= 2;
            if(i%2)
                decomposition_tree[i][p] = decomposition_tree[i-1][2*p] | decomposition_tree[i-1][2*p+1];
            else
                decomposition_tree[i][p] = decomposition_tree[i-1][2*p] ^ decomposition_tree[i-1][2*p+1];
        }
        cout<<decomposition_tree[n][0]<<endl;
    }
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