#include<bits/stdc++.h>

using namespace std;

#define int long long

int dp[11][(1<<20)+1], rating[21];
int n; // 2*n chess players

// happiness = k*(abs(rating[i]-rating[j]))*(gcd(rating[i], rating[j]))

int mask_rec(int board, int mask){

    if(board == n+1){
        return 0;
    }

    if(dp[board][mask]!=-1) return dp[board][mask];

    int ans = 0;
    for(int i=1; i<=2*n; i++){
        for(int j=1; j<=2*n; j++){

            if( !(mask & (1<<(i-1))) && !(mask & (1<<(j-1)))){
                ans = max(ans, mask_rec(board+1, mask | (1<<(i-1)) | (1<<(j-1)) ) + board*(abs(rating[i]-rating[j]))*gcd(rating[i], rating[j]) );
            }
        }
        dp[board][mask] = ans;
    }

    return dp[board][mask];
}

// memo optimization
int dp2[(1<<20)+1];

int mask_rec2(int board, int mask){
    if(board == n+1){
        return 0;
    }

    if(dp2[mask]!=-1) return dp2[mask];

    int ans = 0;
    for(int i=1; i<=2*n; i++){
        for(int j=1; j<=2*n; j++){

            if( !(mask & (1<<(i-1))) && !(mask & (1<<(j-1)))){
                ans = max(ans, mask_rec(board+1, mask | (1<<(i-1)) | (1<<(j-1)) ) + board*(abs(rating[i]-rating[j]))*gcd(rating[i], rating[j]) );
            }
        }
        dp2[mask] = ans;
    }

    return dp2[mask];
}


signed main(){

    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=2*n; i++){
        cin>>rating[i];
    }

    int ans = mask_rec(1, 0);
}


// if order doesnt matter

int mask_rec3(int board, int mask){

    if(board == n+1) return 0;


    if(dp[mask]!=-1){
        int ans = 0;
        int j = log2(((mask|(mask+1)) ^(mask)));

        for(int i=1; i<=2*n; i++){
            if( !(mask & (1<<(i-1))) && !(mask & (1<<(j-1)))){
                ans = max(ans, mask_rec(board+1, mask | (1<<(i-1)) | (1<<(j-1)) ) + board*(abs(rating[i]-rating[j]))*gcd(rating[i], rating[j]) );
            }
        }
        dp[mask] = ans;
    }
    return dp[mask];
}