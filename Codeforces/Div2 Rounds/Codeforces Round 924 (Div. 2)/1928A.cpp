#include"../../../template.h"

void solve(){
    ll a,b;
    cin >> a >> b;
    ll x= min(a,b), y= max(a,b);
    if(x%2){
        if(y%2==0 && y/2!=x){
            Yes();
        }
        else{
            cout<<"NO\n";
        }
    }
    else{
        cout<<"YES\n";
    }
    
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