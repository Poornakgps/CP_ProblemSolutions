#include<bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for(ll i = a; i < (b); i+=c)
#define all(x) begin(x), end(x)
typedef long long ll;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define endl() cout<<endl
#define Yes() cout<<"YES\n"
#define No() cout<<"NO\n"


/************************** ........... ****************************/
void primeFactors(ll n, map<ll,ll> &mp) { 

    while (n % 2 == 0) { 
        mp[2]++;
        n = n/2; 
    } 
    for (ll i = 3; i <= sqrt(n); i = i + 2) { 
        while (n % i == 0) { 
            mp[i]++;
            n = n/i; 
        } 
    } 
    if (n > 2) 
        mp[n]++;
}

void solve(){ 

    ll n;
    cin>>n;
    ll one =0, three = 0, six = 0, ten = 0, fifteen = 0;
    ll kk=n;
    fifteen = n/15;
    n = n%15;
    

    if(n==0){
        cout<<fifteen<<endl;
        return;
    }
    
    if(kk>15){
        if(n==1 || n==3 || n==5 || n==6 || n==10 ){
            cout<<fifteen+1<<endl;
            return;
        }
        else if(n==14){
            cout<<fifteen+3<<endl;
            return;
        }
        else{
            cout<<fifteen+2<<endl;
            return;
        }

    }
    else{
        if(n==14){
            cout<<3<<endl;
        }
        else if(n==13){
            cout<<2<<endl;
        }
        else if(n==12){
            cout<<2<<endl;
        }
        else if(n==11){
            cout<<2<<endl;
        }
        else if(n==10){
            cout<<1<<endl;
        }
        else if(n==9){
            cout<<2<<endl;
        }
        else if(n==8){
            cout<<3<<endl;
        }
        else if(n==7){
            cout<<2<<endl;
        }
        else if(n==6){
            cout<<1<<endl;
        }
        else if(n==5){
            cout<<3<<endl;
        }
        else if(n==4){
            cout<<2<<endl;
        }
        else if(n==3){
            cout<<1<<endl;
        }
        else{
            cout<<n<<endl;
        }
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