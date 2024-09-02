#include<bits/stdc++.h>

using namespace std;
#define int long long

int dp[35][35];
int n, piles;
int pref[35];

int rec(int i, int j){

    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = 1e9;

    for(int k = i; k<j; k+=(piles-1)){
        int lft = rec(i, k);
        int rgt = rec(k+1, j);
        ans = min(ans, lft + rgt );
    }
    if((j-i)%(piles-1) == 0){
        ans += (pref[j]-pref[i-1]);
    }
    return dp[i][j] = ans;
}
signed main(){

    int t;
    cin>>t;

    while(t--){

        cin>>n>>piles;
        memset(dp, -1, sizeof(dp));
        vector<int> a(n);
        for(auto &it: a){
            cin>>it;
        }
        if((n-1)%(piles-1) != 0){
            cout<<-1<<endl;
            continue;
        }
        for(int i=1; i<=n; i++){
            pref[i] = pref[i-1] + a[i-1];
        }
        cout<<rec(1, n)<<endl;
    }
}
      