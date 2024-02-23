#include "../../template.h"

void solve(){

    ll n,m;
    cin>>n>>m;

    ll ans=0;

    if(n>m){
        cout<<0<<endl;
        return;
    }
    bool change = false;
    ll done=1e12;
    for(int bit=29; bit>=0; bit--){
        if((((n>>bit) & 1 ) && ((m>>bit) & 1))){
            m= m^(1<<bit);
            n= n^(1<<bit);
            continue;
        }
        if(((m>>bit) & 1 )&& !change){
            m= m^(1<<bit);
            ans+=(1<<bit);
            continue;
        }
        if(((n>>bit) & 1 ) && !((m>>bit) & 1)){
            change= true;
            done= min(ans, done);
            break;
        }
        else{
            done= min(ans+(1<<bit), done);
        }
    }
    
    cout<<done<<endl;
}

int main() {

    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
}