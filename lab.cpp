#include<bits/stdc++.h>

using namespace std;

#define ll long long


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll x, y;
        cin>>x>>y;
        int n = s.size();
        ll ans = 0;
        deque<int> ind;
        if(x>y){
            string comp = "";
            
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(s[i]=='a'){
                    cnt++;
                    ind.push_back(i);
                }
                else if(s[i]=='b'){
                    if(cnt){
                        s[i]='.';
                        cnt--;
                        ans+=x;
                        s[ind.back()]='.';
                        ind.pop_back();
                    }
                }
                else{
                    ind.clear();
                    cnt = 0;
                }
            }
            for(int i=0; i<n; i++){
                if(s[i]=='.'){
                    continue;
                }
                comp += s[i];
            }
            cnt = 0;
            for(int i=0; i<comp.size(); i++){
                if(comp[i]=='b'){
                    cnt++;

                }
                else if(comp[i]=='a'){
                    if(cnt){
                        comp[i]='.';
                        cnt--;
                        ans+=y;
                    }
                }
                else{
                    cnt = 0;
                }
            }
        }
        else{
            string comp = "";
            
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(s[i]=='b'){
                    cnt++;
                    ind.push_back(i);
                }
                else if(s[i]=='a'){
                    if(cnt){
                        s[i]='.';
                        cnt--;
                        ans+=y;
                        s[ind.back()]='.';
                        ind.pop_back();
                    }
                }
                else{
                    ind.clear();
                    cnt = 0;
                }
            }
            // cout<<ans<<endl;
            for(int i=0; i<n; i++){
                if(s[i]=='.'){
                    continue;
                }
                comp += s[i];
            }
            cnt = 0;
            for(int i=0; i<comp.size(); i++){
                if(comp[i]=='a'){
                    cnt++;
                }
                else if(comp[i]=='b'){
                    if(cnt){
                        comp[i]='.';
                        cnt--;
                        ans+=x;

                    }
                }
                else{
                    
                    cnt = 0;
                }
            }
        }
        cout<<ans<<endl;
    }
}