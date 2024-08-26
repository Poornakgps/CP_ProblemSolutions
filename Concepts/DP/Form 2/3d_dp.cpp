#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


/*
You are standing on the lowest row of a chessboard and can only move, upwards and leftwards or upwards and 
rightwards. There is a predefined score on each cell of the chessboard. You can start from any cell in the 
lowest row and you have to reach the uppermost row such that your score is the maximum possible and it is 
divisible by K. You have to find the maximal score you can achieve.
T<=100, M,N <= 100, K<=11
*/
int n,m,k;
int a[101][101];
int dp[101][101][12];
int main(){
    IOS
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                char c;
                cin>>c;
                a[i][j]=c-'0';
            }
        }
        memset(dp,-1,sizeof(dp));
        for(int j=1; j<=m; ++j){
            int t=a[n][j]%k;
            dp[n][j][t] = a[n][j];
        }
        for(int i=n-1; i>=1; --i){
            for(int j=1; j<=m; ++j){
                for(int l=0; l<k; ++l){
                    if(j>1 && dp[i+1][j-1][l]>=0){
                        int t=dp[i+1][j-1][l]+a[i][j];
                        if(dp[i][j][t%k]<t){
                            dp[i][j][t%k]=t;
                        }
                    }
                    if(j<m && dp[i+1][j+1][l]>=0){
                        int t=dp[i+1][j+1][l]+a[i][j];
                        if(dp[i][j][t%k]<t){
                            dp[i][j][t%k]=t;
                        }
                    }
                }
            }
        }
        int ans=-1;
        for(int j=1; j<=m; ++j){
            if(ans < dp[1][j][0]){
                ans=dp[1][j][0];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}