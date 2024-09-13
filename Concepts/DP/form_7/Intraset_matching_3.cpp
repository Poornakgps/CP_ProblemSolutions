#include<bits/stdc++.h>

using namespace std;

#define int long long

int dp[11][(1<<20)+1], rating[21];
int n; // 2*n chess players

// happiness = k*(abs(rating[i]-rating[j]))*(gcd(rating[i], rating[j]))
int gcd(int a, int b){ if(b==0) return a; else return gcd(b,a%b); }

int mask_rec(int board, int mask){

    if(board == n+1){
        return 0;
    }

    if(dp[board][mask]!=-1) return dp[board][mask];

    int ans = 0;
    for(int i=0; i<2*n; i++){
        for(int j=0; j<2*n; j++){

            if( !(mask & (1<<(i))) && !(mask & (1<<(j)))){
                ans = max(ans, mask_rec(board+1, mask | (1<<(i)) | (1<<(j)) ) + board*(abs(rating[i]-rating[j]))*gcd(rating[i], rating[j]) );
            }
        }
        dp[board][mask] = ans;
    }

    return dp[board][mask];
}
int pre_gcd[20][20];

// memo optimization
int dp2[(1 << 20) + 1];

int mask_rec2(int board, int mask) {
    if (board == n + 1) {
        return 0;
    }

    if (dp2[mask] != -1) return dp2[mask];

    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if ((mask & (1 << i)) == 0 && (mask & (1 << j)) == 0 && i != j) { // Additional check to avoid (i, i) pair
                ans = max(ans, mask_rec2(board + 1, mask | (1 << i) | (1 << j)) + board * (abs(rating[i] - rating[j])) * pre_gcd[i][j]);
            }
        }
    }

    dp2[mask] = ans; // Correct placement of memoization assignment
    return dp2[mask];
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        cin >> n;
        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));
        for(int i=0; i<2*n; i++){
            cin>>rating[i];
        }
       for(int i=0;i<2*n;i++){
           for(int j=0;j<2*n;j++){
               if(i==j)continue;
               pre_gcd[i][j]=gcd(rating[i],rating[j]);
                pre_gcd[j][i]= pre_gcd[i][j];
           }
       }
        int ans = mask_rec2(1, 0);
        cout<<ans<<endl;
    }

}


// if order doesnt matter

// int mask_rec3(int board, int mask){

//     if(board == n+1) return 0;


//     if(dp[mask]!=-1){
//         int ans = 0;
//         int j = log2(((mask|(mask+1)) ^(mask)));

//         for(int i=1; i<=2*n; i++){
//             if( !(mask & (1<<(i-1))) && !(mask & (1<<(j-1)))){
//                 ans = max(ans, mask_rec(board+1, mask | (1<<(i-1)) | (1<<(j-1)) ) + board*(abs(rating[i]-rating[j]))*gcd(rating[i], rating[j]) );
//             }
//         }
//         dp[mask] = ans;
//     }
//     return dp[mask];
// }