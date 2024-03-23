#include<bits/stdc++.h>
#include<chrono>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
 
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
 
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for(ll i = a; i < (b); i+=c)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define endl() cout<<endl
#define Yes() cout<<"Yes\n"
#define No() cout<<"No\n"

/*
 1 2 3 4
 2 1 4 3
 3 4 1 2
*/

void solve(){

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n+1);

    
    k = min(k,n);
    ll kk=k;
    ll colors = n/k + (n%k!=0);
    rep(i, 1, n+1, k){
        ll cnt=k/2;
        for(int j = i; j<min(i+k,n+1); j++){
            if(j<=(i + k/2 + k%2 -1)){
                a[j]= i+cnt ;
                cnt++;
            }
            else{
                if(cnt==k){
                    cnt=0;
                }
                a[j]=i+cnt;
                cnt++;
            }
        }
    }

    if(n%k!=0){
        ll cnt=(n%k)/2;
        ll i = n-n%k+1;
        k = n%k;
        //cout<<cnt << i<<endl;
        for(int j = i; j<n+1; j++){
            if(j<=(i + k/2 + k%2 -1)){
                a[j]= i+cnt ;
                cnt++;
            }
            else{
                if(cnt==k){
                    cnt=0;
                }
                a[j]=i+cnt;
                cnt++;
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<a[i]<<" ";
    }
    endl();
    cout<<colors<<endl;
    ll cnt=0;
    for(int i=1; i<=n; i++){
        cout<<colors<<" ";
        cnt++;
        if(cnt==kk){
            cnt=0;
            colors--;
        }
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