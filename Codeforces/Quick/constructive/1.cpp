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
#define fill(v) for(auto& i: v) cin>>i;
#define has(c, x) {return c.find(x)!=c.end();}
#define pr(v) for(auto i: v) cout<<i<<" "; cout<<endl;
#define pr1(v, i) for(auto j: v) cout<<j[i]<<" "; cout<<endl; 
#define del(s, x) if(s.find(x)!=s.end()) s.erase(s.find(x)) 
#define show(x) cout<<#x<<": "<<x<<" ";
#define rev(v) reverse(v.begin(), v.end())
#define endl() cout << endl
#define mod_10 1000000007
#define mod_9 998244353
#define MAXN 100005
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"

/***************************************C-H-A-O-S**************************************/

// https://codeforces.com/contest/1974/problem/F

void solve() {

    ll a, b, n, m; 
    cin >> a >> b >> n >> m;

    vector<pair<ll,ll>> chips(n);

    for(auto &i: chips) cin >> i.ff >> i.ss;

    vector<pii> column, row;

    for(auto i: chips) {
        column.pb({i.ss, i.ff});
        row.pb(i);

    }

    sort(all(column));

    sort(all(row));

    ll c_l = 1, c_r = b, r_u = 1, r_d = a;

    ll alice = 0, bob = 0;

    set<pii> del;

    ll hl = 0, hr = n-1;
    ll vl = 0, vr = n-1;

    for(int i = 0; i < m; i++) {
        char c;
        cin >> c;
        ll k;
        cin >> k;

        ll score = 0;

        if(c == 'U') {
            r_u += k;

            while( vl <= vr && row[vl].ff < r_u) {
                if(del.find(row[vl]) == del.end()) {
                    score++;
                    del.insert(row[vl]);
                }
                vl++;
            }
            
        } 
        else if(c == 'D') {
            r_d -= k;

            while( vl <= vr && row[vr].ff > r_d) {
                if(del.find(row[vr]) == del.end()) {
                    score++;
                    del.insert(row[vr]);
                }
                vr--;
            }
        } 
        else if(c == 'L') {
            c_l += k;

            while( hl <= hr && column[hl].ff < c_l) {
                if(del.find({column[hl].ss, column[hl].ff}) == del.end()) {
                    score++;
                    del.insert({column[hl].ss, column[hl].ff});
                }
                hl++;
            }
        } 
        else if(c == 'R') {
            c_r -= k;

            while( hl <= hr && column[hr].ff > c_r) {
                if(del.find({column[hr].ss, column[hr].ff}) == del.end()) {
                    score++;
                    del.insert({column[hr].ss, column[hr].ff});
                }
                hr--;
            }
        }

        i%2 ? bob += score : alice += score;
    }

    cout << alice << " " << bob << endl;


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
