#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll dp[5005][5005];
void pre(){

    for(int i=1; i<=5005; i++){
        for(int j=i; j<=5005; j++){

            if(i==j || i==1){
                dp[i][j] = 1;
            }
            else{

            }
        }
    }

}

void solve(){
    int n, k;
    cin>>n>>k;

    cout<<dp[n][k]<<endl;
}
int main(){
    pre();

    int t;
    cin>>t;

    while(t--){
        solve();
    }
}