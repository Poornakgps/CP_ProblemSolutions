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
#define  MAXN 200005
#define N_LMT 100001

/***************************************C-H-A-O-S**************************************/

void solve() {

    ll n, k;
    cin >> n >> k;

    string s, t;
    cin>>s>>t;

    char curr = s[0];
    ll ind = 0;

    vector<pair<ll,char>> ans;
    char prev = '.';
    ll p = 0;
    for(int i=0; i<n; i++){
        if(i>ind){
            if(s[i] != prev){
                p = i;
                prev = curr;
            }
            ind = i;
            curr = s[i];
        }
        s[i] = curr;
        if(curr == t[i]){
            continue;
        }
        if(curr != t[i]){

            if(prev == t[i]){
                ind = max(p+k-1, i);
                curr = t[i];
                s[i] = t[i];
                ans.pb({(max(p, i-k+1)), curr});
            }
            else if(i+k-1<n){
                curr = t[i];
                ind = i+k-1;
                s[i] = curr;
                prev = curr;
                p = i;
                ans.pb({i+1, curr});
            }

        }
        else{
            break;
        }
    }
    if(s!=t){
        cout<<-1<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it.ff<<" "<<it.ss<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}