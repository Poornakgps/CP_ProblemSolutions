#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n, m, k;
int dp[2003][2003]; // dp[i][j] is the number of ways to paint first i bricks with j new colors used
bool vis[2003][2003];

int rec(int i, int j){

    // base case
    if(i == n){
        return j == k ? 1 : 0; // Only if exactly k colors are used, it's valid
    }

    // cache check
    if(vis[i][j]){
        return dp[i][j];
    }

    vis[i][j] = true;

    int ans = 0;

    // Transition
    if(i > 0) {
        ans = (ans + 1LL * rec(i + 1, j)) % mod; 
        ans+= ((m-1)*(rec(i+1, j+1)))%mod;
        ans = ans%mod;
    }
    else{
        ans = (ans + m*rec(i + 1, j)) % mod; 
    }

    return dp[i][j] = ans;
}

void iterative(){
    cin>>n>>m>>k;

    memset(dp, 0, sizeof(dp));
    dp[n][0]=1;

    for(int i=n-1; i>=0; i--){
        for(int colors = 0; colors<=k; colors++){
            if(i==n-1){
                dp[i][colors] = (colors == k ? 1 : 0);
                continue;
            }

            dp[i][colors] = (dp[i][colors] + dp[i+1][colors])%mod;
            if(colors>0){
                dp[i][colors] = (dp[i][colors] + (m-1)*dp[i+1][colors-1])%mod;
            }
        }
    }
    cout<<dp[0][k]<<endl;
}

void solve(){
    cin >> n >> m >> k;
    

    memset(dp, 0, sizeof(dp));
    memset(vis, false, sizeof(vis));

    // cout<<n<<" "<<m<<" "<<k<<endl;
    // return;
    cout << rec(0, 0) << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}
