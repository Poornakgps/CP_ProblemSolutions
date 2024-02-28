#include"template.h"

/************************** 1000000007 ****************************/
 
void solve(){
 
    ll n;
    in(n);
 
    ll a[n];
    rep(i,0,n,1) in(a[i]);
 
    ll m;
    in(m);
    ll pref[n+2]={}, suff[n+2]={};
    ll pre[n+2][2]={};
    for(int i=1; i<=n; i++){
        if(i==1){
            pre[i][1]=1;
            continue;
        }
        if(i==n){
            pre[i][0]=1;
            continue;
        }
        if(a[i-1]-a[i-2]<a[i]-a[i-1]){
            pre[i][0]=1;
            pre[i][1]= a[i]-a[i-1];
        }
        else{
            pre[i][1]=1;
            pre[i][0]= a[i-1]-a[i-2];
        }
    }
    for(int i=1; i<=n; i++){
        pref[i]+=(pref[i-1]+pre[i][1]);
    }
    for(int i=n; i>=1; i--){
        suff[i]+=(suff[i+1]+pre[i][0]);
    }
    // for(int i=1; i<=n; i++){
    //     cout<<pref[i]<<" "<<suff[i]<<" "<<i<<endl;
    // }
    // endl();
    while(m--){
        ll x,y;
        ll cost=0;
        in(x), in(y);
        ll r=a[n-1], l=1;
 
        if(y>x){
            if(x==1){
                cout<<pref[y-1]<<endl;
                continue;
            }
            cout<<pref[y-1]-pref[x-1]<<endl;
        }
        else{
            if(y==n){
                cout<<suff[x+1]<<endl;
                continue;
            }
            cout<<suff[y+1]-suff[x+1]<<endl;  
        }
    }
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