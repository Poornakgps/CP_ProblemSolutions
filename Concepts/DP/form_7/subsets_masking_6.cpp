#include<bits/stdc++.h>

using namespace std;

#define int long long

int G_happiness[(1<<16)], n;
int happiness[16][16];

int dp[(1<<16)];

int rec_mask(int mask){
    if(mask == 0) return 0;

    if(dp[mask]!=-1){
        return dp[mask];
    }

    int ans= 0;

    for(int submask = mask; submask; submask= (submask-1)&mask){
        int temp = G_happiness[submask];
        ans = max(ans, temp + rec_mask(mask^submask));
    }
    return dp[mask] = ans;
}

signed main(){

    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>happiness[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));

    // preprocessing group happiness score
    G_happiness[0] = 0;

    for(int mask=1; mask<(1<<n); mask++){
        int temp = -1;
        for(int i=0; i<n; i++){
            if(mask&(1<<i)){ temp = i; break;}
        }
        G_happiness[mask] = 0;

        for(int i=0; i<n; i++){
            if(mask&(1<<i)){
                G_happiness[mask] += happiness[i][temp];
            }
        }
        G_happiness[mask] += G_happiness[mask^(1<<temp)];
    }

    cout<<rec_mask((1<<16)-1)<<endl;
}