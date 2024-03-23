#include<bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for(ll i = a; i < (b); i+=c)
#define all(x) begin(x), end(x)
typedef long long ll;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define endl() cout<<endl
#define Yes() cout<<"YES\n"
#define No() cout<<"NO\n"

void primeFactors(ll n, map<ll,ll> &mp) { 

    while (n % 2 == 0) { 
        mp[2]++;
        n = n/2; 
    } 
    for (ll i = 3; i <= sqrt(n); i = i + 2) { 
        while (n % i == 0) { 
            mp[i]++;
            n = n/i; 
        } 
    } 
    if (n > 2) 
        mp[n]++;
}

void solve() {
    ll n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    
    for(int i=0; i<n; i++){
        if(i%2){
            if( a[i]=='<' && b[i-1]=='<'){
                //cout<<i<<endl;
                cout<<"NO\n";
                return;
            }
        }
        else{
            if(i!=n-1 && a[i-1]=='<' && b[i]=='<'){
                cout<<"NO\n";
                return;
            }
        
        }
    }
    cout<<"YES\n";
    /**
        > > > <
        > > < <
    */

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
