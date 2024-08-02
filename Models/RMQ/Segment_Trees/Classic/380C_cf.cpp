#include<bits/stdc++.h>
#include<chrono>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define size(x) (int)(x).size()
typedef int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mod 1000000007
#define lmt 1000000000000000000
typedef pair<int,int>pii;
typedef pair<int,pii>   node;

const int N = 4000001;

ll t[N+1]={}, c[N+1]={}, o[N+1]={};
string s;

void build(int ind, int l, int r){

    if(r-l<2){
        if(s[l]=='('){
            o[ind]=1;
        }
        else{
            c[ind]=1;
        }
        return;
    }
    ll mid= (l+r)/2;
    build(2*ind, l,mid);
    build(2*ind+1, mid, r);
    int tmp= min(o[2*ind], c[2*ind+1]);

    t[ind]= t[2*ind]+t[2*ind+1]+tmp;

    c[ind]= c[2*ind]+c[2*ind+1]-tmp;

    o[ind]= o[2*ind]+o[2*ind+1]-tmp; 

}

node segment(int x,int y,int id ,int l ,int r ){
    if(l >= y || x >= r){
        return node(0,pii(0,0));
    }
    if(x <= l && r <= y){
        return node(t[id],pii(o[id],c[id]));
    }
    int mid = (l+r)/2;
    node a = segment(x,y,2 * id,l,mid), b = segment(x,y,2 * id + 1,mid,r);
    int T, temp, O, C;
    temp = min(a.second.first , b.second.second);
    T = a.first + b.first + temp;
    O = a.second.first + b.second.first - temp;
    C = a.second.second + b.second.second - temp;
    return node(T,pii(O,C));    
}

void solve(){


    cin>>s;
    ll n=size(s);

    build(1,0,n);   
    ll m;
    cin>>m;
    while(m--){
        ll x,y;
        cin>>x>>y;
        node t= segment(x-1,y,1,0,n);
        cout<<2*t.first<<endl;
    }
}


int main(){

	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int t=1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}