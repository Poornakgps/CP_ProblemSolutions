#include <bits/stdc++.h>

using namespace std;

/*
You are given N marbles in different colours. You have to remove marbles till there are no marbles left. 
Each time you can choose continuous marbles with the same color, remove them and get k*k points 
(where ‘k’ is the length of the continuous marbles removed). Find the maximum points you can get.
*/

int n;
int a[105];
int dp[105][105][105];


int rec(int i, int j, int k){

    // base case
    if(i > j){
        return 0;
    }

    // Cache check
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }

    // Transition

    while(i < j && a[i] == a[i+1]){
        i++;
        k++;
    }

    int ans = rec(i+1, j, 0) + (k+1)*(k+1);
    for(int mid = i; mid < j; mid++){
        
        if(a[i] == a[mid]){
            ans = max(ans, rec(i+1, mid, k+1) + rec(mid+1, j, 0));
        }
        
    }
    return dp[i][j][k] = ans;
}


void solve(){

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<rec(0, n-1, 0)<<endl;
}


int main(){

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }
}