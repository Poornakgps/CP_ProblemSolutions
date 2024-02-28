#include"../../../template.h"


void solve(){
    ll n;
    cin>>n;
    ll arr[n];
    ll s=0;
    ll cnt=0, start=0;
    bool flag=0;
    rep(i,0,n,1){
        cin>>arr[i];
        if(arr[i]==1){
            s=i;
            cnt++;
        }
        if(!flag&& arr[i]==1){
            start= i;
            flag=1;
        }
    }
    cnt--;
    cnt= max(cnt,0ll);
    cout<<max(s-start-cnt, 0ll)<<endl;
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