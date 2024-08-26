#include<bits/stdc++.h>

using namespace std;

int n;
int arr[105];
int dp[105][105];

int rec(int l, int r){
    if(l>=r){
        return 0;
    }

    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    int ans = 0;

    int tot = 0, sum = 0;

    for(int mid = l; mid<r; mid++){
        tot += arr[mid];
    }
    // cout<<l<<" "<<r<<" "<<tot<<endl;
    for(int mid=l; mid<r; mid++){
        sum += arr[mid];
        int temp = rec(l, mid) + rec(mid+1, r) + ((sum%100)*((tot-sum)%100))%100;
        ans = max(ans, temp);
    }
    // cout<<l<<" "<<r<<" "<<ans<<endl;

    return dp[l][r]=ans;
}

void solve(){

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    memset(dp, -1, sizeof(dp));

    cout<<rec(0, n)<<endl;
}


int main(){
    int t = 1;
    cin>>t;

    while(t--){
        solve();
    }
}