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
#define __builtin_popcount(x) count_ones(x)
#define endl() cout<<endl
#define Yes() cout<<"YES\n"
#define No() cout<<"NO\n"

void solve(){

    string s,a;
    cin>>s>>a;
    int k;
    cin>>k;
    set<pair<ll,ll>>st;
    for(int i=0;i<s.size();i++){

        ll pow1=1,pow2=1;
        ll mod1 = 1e9+7, mod2 = 1e9+9;
        ll p1=31,p2=37;
        ll cnt=0;
        ll hash1=0, hash2=0;
        
        for(int j=i; j<s.size(); j++){

            if(a[s[j]-'a']=='0')
                cnt++;

            if(cnt > k) 
                break;

            hash1=((hash1+(s[j]-'a'+1)*pow1))%mod1;

            hash2=((hash2+(s[j]-'a'+1)*pow2))%mod2;

            pow1=(pow1*p1)%mod1;

            pow2=(pow2*p2)%mod2;

            st.insert({hash1,hash2});
        }
    }
    cout<<st.size()<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}