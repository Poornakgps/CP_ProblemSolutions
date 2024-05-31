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

// https://codeforces.com/contest/1974/problem/G
void solve() {

    
    int m, x;
    cin >> m >> x;
    vector<int> c(m);
        
    fill(c);
    
    int budget = 0;
    priority_queue<int> Q;
        
    for (int i = 0; i < m; ++i) {
        if (budget >= c[i]) {
            Q.push(c[i]);
            budget -= c[i];
        } else if (!Q.empty() && Q.top() > c[i]) {
            budget += Q.top() - c[i];
            Q.pop();
            Q.push(c[i]);
        }
        budget += x;
    }
        
    cout << Q.size() << endl;
    

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
