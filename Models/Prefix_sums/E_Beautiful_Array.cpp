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
// max no of digits
void solve() {
    ll n, k;
    cin >> n >> k;
    
    map<ll, vector<ll>> rem;

    for(int i=0; i<n; i++){
        ll x;
        cin >> x;
        rem[x%k].pb(x);
    }
    ll cnt = 0;
    for(auto &it: rem){
        sort(it.ss.begin(), it.ss.end());
        if(it.ss.size() & 1){
            cnt++;
        }
    }
    if(cnt> (n & 1 ) ){
        cout<<-1<<endl;
        return;
    }
    cnt = 0;
    for(auto it: rem){

        if(it.ss.size() & 1){
            ll mn = 1e13;
            vector<ll> pref(n+2, 0), suff(n+2, 0);
            for(int i=0; i<it.ss.size()-1; i+=2){
                pref[i+1] = pref[i] + it.ss[i+1]-it.ss[i];
                
                pref[i+2] = pref[i+1]; 
            } 
            for(int i=it.ss.size()-1; i>0; i-=2){
                suff[i] = suff[i+1] + it.ss[i] - it.ss[i-1];
                suff[i-1] = suff[i];
            }
            for(int i=0; i<it.ss.size(); i++){
                mn = min(mn, suff[i+1]+pref[i]);
            }
            cnt+= mn/k;

        }   
        else{
            for(int i=0; i<it.ss.size()-1; i+=2){
                cnt += ((it.ss[i+1]-it.ss[i])/k);
            }
        }
    }
    cout<<cnt<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}