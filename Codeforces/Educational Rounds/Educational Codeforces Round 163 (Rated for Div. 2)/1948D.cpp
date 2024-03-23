#include<bits/stdc++.h>

using namespace std;

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

void solve(){

    string s;
    cin>>s;
    ll n = s.size();

    for(int i=n/2; i>=1; i--){
        ll ans=0;
        for(int j=1; j<=n-i; j++){
            if(s[j-1]==s[j+i-1] || s[j-1]=='?' || s[j+i-1]=='?')
                ans++;
            else{
                ans=0;
            }
            if(ans==i){
                cout<<2*i<<endl;
                return;
            }
        }
    }
    cout<<0<<endl;
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