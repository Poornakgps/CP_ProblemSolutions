#include"../template.h"

/************************** 1000000007 ****************************/

void solve(){

    ll n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    ll ok=0;
    for(int i=0; i<n; i++){

        if(a[i]==c[i] || b[i]==c[i]){
            ok++;
        }
    }
    if(ok==n){
        cout<<"NO\n";
        return;
    }
    out("YES\n");
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