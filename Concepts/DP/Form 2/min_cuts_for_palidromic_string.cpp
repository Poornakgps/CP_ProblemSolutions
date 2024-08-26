#include<bits/stdc++.h>

using namespace std;

int n;
string s;

int dp[1005][1005];
int rec1(int l, int r){

    if(l>=r){
        return 1;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int ans=0;

    if(s[l]== s[r] && rec1(l+1, r-1)){
        ans = 1;
    }
    return dp[l][r]=ans;
}

int dp2[1005];
int rec2(int i){
    if(i==0){
        return -1;
    }
    if(dp2[i]!=-1){
        return dp2[i];
    }
    int ans = 1e9;

    for(int j=i-1; j>=0; j--){
        if(rec1(j+1, i)){
            ans = min(ans, 1+rec2(j));
        }
    }
    return dp2[i]=ans;
}

void solve(){

    cin>>n;
    cin>>s;
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    cout<<rec2(n)<<endl;


}

int main(){
    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
}