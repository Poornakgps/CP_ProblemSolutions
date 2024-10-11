#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ss second
#define ff first
#define pb push_back


vector<int> z_function(string s){
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for(int i=1; i<n; i++){
        if(i<r){
            z[i] = min(r-i, z[i-l]);
        }
        while(i+z[i]<n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if(i+z[i]>r){
            l = i;
            r=i+z[i];
        }
    }
    return z;
}

void solve(){
    ll n, q;
    cin>>n >>q;

    vector<ll> a(n), ps_cycle(1);

    for (ll &r : a) {
        cin >> r;
        ps_cycle.push_back(ps_cycle.back() + r);
    }
    for (ll &r : a) {
        ps_cycle.push_back(ps_cycle.back() + r);
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        ll i = l/n, j = r/n;
        l %= n; r %= n;
        cout << ps_cycle[n] * (j - i + 1) - ((ps_cycle[i + l] - ps_cycle[i]) + (ps_cycle[j + n] - ps_cycle[j + r + 1])) << endl;
    }
    
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t=1;  
    cin>>t;

    while(t--){
        solve();
    }
}