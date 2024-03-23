#include "../../template.h"

ll pre[322][200005], ipre[320][200005];

void solve(){

    ll n, q;
    cin>>n>>q;

    ll arr[n];
    rep(i, 0, n, 1)
        cin>>arr[i];
    
    ll min_len = sqrt(1.0*n)+1;  // length we pre calculate

    for(int i=0; i<min_len; i++){
        for(int j=0; j<=i; j++)
            pre[i][j]=0, ipre[i][j]=0;
        
        for(int j=0; j<n; j++){
            pre[i][i+j+1]= pre[i][j] + arr[j];
            ipre[i][i+j+1] = ipre[i][j] + arr[j]*(j/(i+1) +1);
        }
    }

    while(q--){
        ll s, d, k, ans=0;
        cin>>s>>d>>k;
        s--;
        if(d > min_len){
            ll j=1;
            for(int i=s; i <= s+d*(k-1); i+=d){
                ans+=(arr[i])*(j);
                j++;
            }
            out(ans);
            continue;
        }
        ans= ipre[d-1][s+d*k] - ipre[d-1][s] - (pre[d-1][s+d*k] - pre[d-1][s])*(s/d);
        out(ans);
        
    }
    endl();
}

int main() 
{
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
