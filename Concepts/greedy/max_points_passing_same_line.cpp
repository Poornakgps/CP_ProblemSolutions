#include<bits/stdc++.h>

using namespace std;
#define ll long long


pair<ll,ll> red_frac(ll a, ll b){
    if(a==0 || b==0){
        return {(a!=0), (b!=0)};
    }
    int neg= 1;
    if(a<0){
        neg = neg*(-1);
        a = abs(a);
    }

    if(b<0){
        neg *= (-1);
        b = abs(b);
    }
    ll x = __gcd(a, b);
    return {a/x, b/x};
}

int main(){

    int n;
    cin>>n;

    pair<ll,ll> a[n];
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin>>a[i].first>>a[i].second;
    }

    for(int i=0; i<n; i++){
        ll same = 0;
        map<pair<ll,ll> , ll> mp;
        for(int j = 0; j<n; j++){
            if(a[i].first != a[j].first && a[i].second != a[j].second){
                mp[red_frac((a[i].second - a[j].second), (a[i].first - a[j].first))]++;
            }
            else{
                same++; // edge case 0/0 is not equal to 1/1
            }
        }

        for(auto it: mp){
            ans = max(ans, same + it.second);
        }
    }
    cout<<ans<<endl;
}