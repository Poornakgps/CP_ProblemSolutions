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


/************************** 1000000007 ****************************/

void solve(){

    ll n,m;
    cin>>n>>m;
    ll flag=0;
    for(int i=63 ; i>=0; i--){
        // cout<< (!((n>>i)&1)) <<" "<< ((m>>i)&1) <<endl;
        if((((n>>i)&1) && ((m>>i)&1))){
            break;
        }
        if(((n>>i)&1) && !((m>>i)&1)){
            flag++;
            if(flag==2){
                break;
            }
            continue;
        }
        //cout<<flag<<" "<<i<<" "<<(!((n>>i)&1) )<<" "<<((m>>i)&1)<<endl;
        if(!((n>>i)&1) && ((m>>i)&1) && flag<=1){
            cout<<-1<<endl;
            return;
        }
    }
    if(flag<=1){
        cout<<1<<endl;
        cout<<n<<" "<<m<<endl;
        return;
    }
    vector<ll> ans;
    ans.pb(n);
    ll sm=0;
    for(int i=63; i>=0; i--){
        if(((n>>i)&1) && flag){
            flag--;
        }
        if(flag==0 && ((n>>i)&1)){
            ll k= pow(2,i);
            n= m | k;
            ans.pb(n);
            ans.pb(m);
            break;
        }
    }
    cout<<ans.size()-1<<endl;
    for(auto x: ans){
        cout<<x<<" ";
    }
    endl();
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
