#include<bits/stdc++.h>

using namespace std;

int n, k, a[1010], pre[1010];
int dp[1010][1010];

bool done[1010][1010];

int rec(int i, int k){
    if(k==0){
        return 0;
    }
    if(i<0){
        return -1e9;
    }
    if(done[i][k]){
        return dp[i][k];
    }
    done[i][k] = 1;
    int ans = rec(i-1, k);
    for(int j=0; j<=i; j++){
        ans=max(ans, rec(j-2, k-1)+pre[i+1]-pre[j]);
    }
    return dp[i][k] = ans;
}

void solve(){

    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    pre[0]=0;

    for(int i=1; i<=n; i++){
        pre[i]=pre[i-1]+a[i-1];
    }
    memset(done, 0, sizeof(done));

    cout<<rec(n-1, k)<<endl;
}

int main(){
    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
}