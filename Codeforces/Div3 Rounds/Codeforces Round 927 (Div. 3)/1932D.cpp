#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



void solve(){

    ll n;
    cin>>n;
    char c;
    cin>>c;
    deque<ll> v[4];
    for(int i=0; i<2*n; i++){
        string s;
        cin>>s;
        //cout<<s<<" ";
        if(s[1]=='C'){
            v[0].pb((ll)(s[0]-'0'));
        }
        else if(s[1]=='D'){
            v[1].pb((ll)(s[0]-'0'));
        }
        else if(s[1]=='H'){
            v[2].pb((ll)(s[0]-'0'));
        }
        else{
            v[3].pb((ll)(s[0]-'0'));
        }
    }
    ll odd=0;
    ll in=0;
    ll h=0;
    if(c=='C')
        h=0;
    else if(c=='D')
        h=1;
    else if(c=='H')
        h=2;
    else
        h=3;
    
    for(auto &it: v){
        sort(all(it));
        if(it.size()%2 && in!=h){
            odd++;
        }
        in++;
    }

    ll p = v[h].size();
    if(odd>p){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    in=0;
    string str = "CDHS";
    for(auto it: v){
        if(in!=h){
            if(it.size()%2){
                cout<<it.front()<<str[in]<<" "<<v[h].front()<<str[h]<<"\n";
                v[h].pop_front();
                it.pop_front();
            }
            for(int i=0; i<it.size(); i+=2){
                cout<<it[i]<<str[in]<<" "<<it[i+1]<<str[in]<<"\n";
            }
        }
        in++;
    }
    for(int i=0; i<v[h].size(); i+=2){
        cout<<v[h][i]<<str[h]<<" "<<v[h][i+1]<<str[h]<<"\n";
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