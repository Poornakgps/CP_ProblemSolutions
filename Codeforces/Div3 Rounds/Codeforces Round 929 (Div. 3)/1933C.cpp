#include"../../../template.h"

void solve(){ 
 
    ll a,b,l;
    cin>>a>>b>>l;
    ll t1=1;
    set<ll> st;
    for(int i=0; ;i++){
        ll t2=1;
        for(int j=0; ;j++){
            if(l%(t1*t2)==0){
                st.insert(l/(t1*t2));
            }
            else{
                break;
            }
            t2= t2*b;
        }
        t1= t1*a;
        if(l%t1!=0){
            break;
        }
    }
    cout<<st.size()<<endl;
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