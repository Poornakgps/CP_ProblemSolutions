#include "../template.h"

void solve(){
    ll n;
    cin>>n;

    ll a[n+2], d[n+2];
    a[0]=0, a[n+1]=0, d[0]=0, d[n+1]=0;
    rep(i,1,n+1,1) cin>>a[i];
    rep(i,1,n+1,1) cin>>d[i];
    
    ll prev[n+2]={}, nxt[n+2]={};
    set<ll> alive;
    for(int i=1; i<=n; i++){
        nxt[i]= i+1;
        prev[i]=i-1;
        alive.insert(i);
    }
    bool flag=0;
    for(int round=1; round<=n; round++){
        vector<ll> dead;
        if(flag){
            cout<<0<<" ";
            continue;
        }
        set<ll> neighbors;
        for(auto it: alive){
            if(a[prev[it]]+a[nxt[it]]>d[it]){
                dead.pb(it);
                if(prev[it]>0)
                    neighbors.insert(prev[it]);
                if(nxt[it]<=n)
                    neighbors.insert(nxt[it]);
                continue;
            }
        }
        cout<<size(dead)<<" ";
        if(size(dead)==0){
            flag=1;
        }
        for(auto it: dead){
            nxt[prev[it]] = nxt[it];
            prev[nxt[it]] = prev[it]; 
            neighbors.erase(it);
        }
        alive= neighbors; // neighbors only take into consideration for the next round
    }
    endl();
}

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    
    while(t--){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}