#include "template.h"

/************************** 1000000007 ****************************/

void solve(){
 
    ll n;
    in(n);
    vector<ll> ans;
    bool flag=true;
 
    for(int i=61; i>=0; i--){
 
        if((n>>i)>0 && flag){
 
            flag=false;
            for(int j=1; j<=i; j++){
                ans.pb(j);
            }
            ll p= pow(2,i);
            n= n^(p);
            continue;
        }
        if((n>>i)&1){
            ans.pb(i+1);
            ll p= pow(2,i);
            n= n^(p);
        }
    }
    if(size(ans)>200){
        cout<<-1<<endl;
        return;
    }
    cout<<size(ans)<<endl;
    for(auto it: ans) cout<<it<<" ";
    endl();
} 
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
 
    return 0;
}